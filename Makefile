CC      = gcc
CFLAGS  = -g -march=native
RM      = rm -f
PREFIX  = /usr/local/bin

default: all

all: talc

talc: main.c
	$(CC) $(CFLAGS) -o talc main.c
	chmod +x talc

install: talc
	install -d $(DESTDIR)$(PREFIX)
	install -m 755 talc $(DESTDIR)$(PREFIX)/talc

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/talc

clean veryclean:
	$(RM) talc
