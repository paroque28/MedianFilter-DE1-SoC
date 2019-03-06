CC=gcc
CFLAGS=-lpng

split: src/main.c src/utils/split.c
	$(CC) -o $@ src/main.c src/utils/split.c $(CFLAGS) -g -ggdb