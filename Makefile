CC=gcc
CFLAGS= -Isrc -g -ggdb
DEPS= $(wildcard src/*.c) $(wildcard src/utils/*.c)
HEADERS=

median_filter: $(DEPS) $(HEADERS)
	$(CC) -o $@ $(DEPS) $(CFLAGS)