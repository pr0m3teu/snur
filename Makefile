CFLAGS=-Wall -Wextra -std=c11 -pedantic

main: main.c string_builder.o
	clang -o main $(CFLAGS) main.c string_builder.o

string_builder.o: string_builder.h string_builder.c
	clang -c $(CFLAGS) string_builder.c

.PHONY: clean
clean:
	rm -rf *.o
