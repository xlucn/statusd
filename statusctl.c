#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>   /* socket, connect */
#include <sys/un.h>       /* struct sockaddr_un */
#include <unistd.h>       /* write, close */

#define PIPE_NAME "/tmp/statusd.pipe"
#define SOCKET_NAME "/tmp/statusd.socket"
#define BUFFER_SIZE 32

int open_pipe()
{
	struct stat st;

	stat(PIPE_NAME, &st);
	if (!S_ISFIFO(st.st_mode)) {
		fprintf(stderr, "%s is not a fifo.\n", PIPE_NAME);
		exit(1);
	}

	return open(PIPE_NAME, O_WRONLY | O_NONBLOCK);
}

int open_socket()
{
	int s;
	struct sockaddr_un addr;

	s = socket(AF_UNIX, SOCK_STREAM, 0);

	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

	if (connect(s, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
		fprintf(stderr, "statusd is not running");
		exit(1);
	}

	return s;
}

int main (int argc, char *argv[])
{
	int res, fd;
	char *button, *seg, *action, message[BUFFER_SIZE];

	fd = open_pipe();

	button = getenv("BUTTON");
	if (argc == 2) {
		seg = argv[1];
		snprintf(message, BUFFER_SIZE, "%s,%s", seg, button);
	} else if (argc == 3) {
		seg = argv[1];
		action = argv[2];
		snprintf(message, BUFFER_SIZE, "%s,%s", seg, action);
	} else {
		fprintf(stderr, "wrong command\n");
	}

	write(fd, message, strlen(message));
	close(fd);

	return 0;
}
