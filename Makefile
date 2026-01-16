CC=clang
CFLAGS=-Wall -Wextra

all:
	$(CC) *.c -o app $(CFLAGS) -lm

clean:
	rm -f app
