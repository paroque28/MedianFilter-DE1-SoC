CC=gcc
CFLAGS=-lpng
DEPS= src/image.c src/utils/split.c src/utils/convert.c src/utils/print.c src/utils/io.c
HEADERS= src/image.h src/utils/split.h src/utils/convert.h src/utils/print.h src/utils/io.h

split: src/main.c $(DEPS) $(HEADERS)
	$(CC) -o $@ src/main.1.c  $(DEPS) $(CFLAGS) -g -ggdb