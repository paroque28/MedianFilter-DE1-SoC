CC=gcc
CFLAGS= -Isrc -lpng -g -ggdb
DEPS= $(wildcard src/*.c) $(wildcard src/utils/*.c)
HEADERS=

median_filter: $(DEPS) $(HEADERS)
	$(CC) -o $@ src/main.c  $(DEPS) $(CFLAGS)