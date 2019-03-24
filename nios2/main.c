#include "sys/alt_stdio.h"
#include <system.h>
#include <string.h>

volatile char * sdram_mem = (char *) SDRAM_CONTROLLER_BASE + 0x2000;

volatile unsigned int * leds = (unsigned int *) LEDS_BASE;


int main()
{ 
  alt_putstr("Median Filter!\n");

  printf("SDRAM Memory offset: %X\n", sdram_mem);
  printf("SDRAM SPAN: %X\n", SDRAM_CONTROLLER_BASE);

  char src[] = "Nothing new\n";
  strcpy(sdram_mem,src);
  *leds = 0;
  while (!*leds){
  	  alt_putstr("LEDS: ");
  	  printf("%X\n", *leds);
  	  usleep(200000); //one second
    }
  /* Event loop never exits. */
  while (1){
	  printf("SDRAM mem: ");
	  alt_putstr(sdram_mem);
  }

  return 0;
}
