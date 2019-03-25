CFLAGS= -Isrc -g -ggdb -Ilib/hwlib/include -Ilib/hwlib/include/soc_cv_av -Dsoc_cv_av -I../nios2_bsp -lpng -static 
DEPS= $(wildcard src/*.c)  
HEADERS= $(wildcard src/*.h)

ARM: $(DEPS) $(HEADERS)
	$(CC) -o $@ $(DEPS) $(CFLAGS)
