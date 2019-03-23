#include "sys/alt_stdio.h"
#include <system.h>

volatile const char * onchip_mem = (char *) ONCHIP_MEMORY_BASE;

int main()
{ 
  alt_putstr("Median Filter!\n");

  char src[] = "Nothing new\n";
  strcpy(onchip_mem,src);

  /* Event loop never exits. */
  while (1){
	  alt_putstr("Onchip mem: ");
	  alt_putstr(onchip_mem);
	  usleep(100000);
  }

  return 0;
}