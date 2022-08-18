CC=gcc

CFLAGS= -std=c99 -g -O0 

all: test

ord: OrdenaPthread.c
	$(CC) $(CFLAGS) -o ord OrdenaPthread.c

test: ord
	./ord

clean:
	rm -rf *.o ord