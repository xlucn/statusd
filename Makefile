PREFIX = /usr/local

install:
	install statusc statusd ${PREFIX}/bin

uninstall:
	rm -f ${PREFIX}/bin/statusc ${PREFIX}/bin/statusd
