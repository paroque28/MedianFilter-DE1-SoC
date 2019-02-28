CC=gcc
CFLAGS=-lpng

split:
	$(CC) -o $@ src/split.c $(CFLAGS)