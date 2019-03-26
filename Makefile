
CFLAGS= -Isrc -g -ggdb -IARM/lib/hwlib/include -IARM/lib/hwlib/include/soc_cv_av -Dsoc_cv_av -Inios2_bsp 
DEPS= $(wildcard src/*.c) $(wildcard src/utils/*.c)
HEADERS=

median_filter: $(DEPS) $(HEADERS)
	$(CC) -o $@ $(DEPS) $(CFLAGS)