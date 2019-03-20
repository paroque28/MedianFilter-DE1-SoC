CC=arm-linux-gnueabihf-gcc 
CFLAGS=-Ilibs/include
DEPS= 
HEADERS= src/hps_linux.h

main: src/main.c $(DEPS) $(HEADERS)
	$(CC) -o $@ src/main.c  $(DEPS) $(CFLAGS) -g -ggdb