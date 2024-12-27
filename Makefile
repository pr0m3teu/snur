CFLAGS=-Wall -Wextra -std=c11 -pedantic
CC=gcc
main: main.c snur.o
	$(CC) -o main $(CFLAGS) main.c snur.o

snur.o: snur.h snur.c
	$(CC) -c $(CFLAGS) snur.c

.PHONY: clean
clean:
	rm -rf *.o
