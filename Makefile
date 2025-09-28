CC      = gcc
CFLAGS  = -g -march=native
RM      = rm -f

default: all

all: talc

talc: main.c
		$(CC) $(CFLAGS) -c main.c -o talc
		chmod +x talc

clean veryclean:
		$(RM) talc
