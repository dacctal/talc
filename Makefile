CC      = gcc
RM      = rm -f
PREFIX  ?= /usr/local

default: all

all: talc

talc: main.c
	$(CC) -o talc main.c
	chmod +x talc

install: talc
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 talc $(DESTDIR)$(PREFIX)/bin/talc

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/bin/talc

clean veryclean:
	$(RM) talc
