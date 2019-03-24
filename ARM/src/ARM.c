/*
 ============================================================================
 Name        : ARM.c

 Author      : Pablo Rodriguez Quesada
 Version     :
 Copyright   : BSD 3-Clause License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "ARM.h"



//#define LED_PIO_SPAN            0x10

int main(int argc, char *argv[])
{
	if(argc != 2){ // argv[1]: image file , argv[2]: percentage
	    printf("Not enough arguments!!\n");
	    abort();
	  }

	volatile char *sdram;
	volatile unsigned int *leds;
	int fd;
	int i;

	fd = open("/dev/mem", (O_RDWR | O_SYNC));


	//Map onchip_mem Physical Address to Virtual Address Space
	sdram = mmap( NULL, SDRAM_CONTROLLER_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, (ALT_HPS2FPGASLVS_OFST + SDRAM_CONTROLLER_BASE + 0x2000) );

	printf(sdram);
	for (i=0; i < 12; i++)
	{
	   *(sdram+i) = 'a';
	   *(sdram+i+1) = '\0';
	   usleep(1000*1000);
	   printf("------------\nchar: %c\n",*sdram);
	   printf(sdram);
	   printf("\n");
	}



	leds =  mmap( NULL, LEDS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, (ALT_LWFPGASLVS_OFST + LEDS_BASE) );

	*leds = 0xAA;


	//Unmap
	munmap(sdram, SDRAM_CONTROLLER_SPAN);
	munmap(leds, LEDS_SPAN);

	close(fd);
	return(0);
}
