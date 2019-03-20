CC=arm-linux-gnueabihf-gcc 
CFLAGS=-Ilibs/hwlib/include -Ilibs/hwlib/include/soc_cv_av
DEPS= 
HEADERS= src/hps_linux.h src/hps_soc_system.h ../quartus/software/MedianFilter_bsp/system.h

main: src/main.c $(DEPS) $(HEADERS)
	$(CC) -o $@ src/main.c  $(DEPS) $(CFLAGS) -g -ggdb