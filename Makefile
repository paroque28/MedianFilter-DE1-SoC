CC=gcc
CFLAGS=-lpng

split: src/split.c
	$(CC) -o $@ src/split.c $(CFLAGS) -g -ggdb