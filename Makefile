PREFIX = /usr/local

all: statusctl

statusctl: statusctl.c

clean:
	rm statusctl

install:
	install statusd statusctl ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/{statusd,statusctl}
