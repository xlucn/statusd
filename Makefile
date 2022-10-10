PREFIX = /usr/local

all: statusctl

statusctl: statusctl.c

install:
	install statusc statusd ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/statusc ${PREFIX}/bin/statusd
