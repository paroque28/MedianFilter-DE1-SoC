CC=gcc
CFLAGS= -Isrc -lpng -g -ggdb -Ilib
DEPS= $(wildcard src/*.c) $(wildcard src/utils/*.c)
HEADERS=

median_filter: $(DEPS) $(HEADERS)
	$(CC) -o $@ $(DEPS) $(CFLAGS)