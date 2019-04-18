CGIBIN ?= /usr/lib/cgi-bin

CFLAGS = -Os

shutdown: shutdown.c

.PHONY: clean
clean:
	rm -f shutdown *~

.PHONY: install
install: shutdown
	mkdir -p ${CGIBIN}
	install -o root -g root -m 4755 shutdown ${CGIBIN}/shutdown

.PHONY: uninstall
uninstall:
	rm -f ${CGIBIN}/shutdown
