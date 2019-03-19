CC=arm-linux-gnueabihf-gcc 
CFLAGS=-Ilibs/include
DEPS= #libs/alt_generalpurpose_io.c 
HEADERS= #libs/include/alt_generalpurpose_io.h

main: src/main.c $(DEPS) $(HEADERS)
	$(CC) -o $@ src/main.c  $(DEPS) $(CFLAGS) -g -ggdb