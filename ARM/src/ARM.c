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

int main(void)
{

	volatile char *onchip_mem;
	volatile unsigned int *leds;
	int fd;
	int i;


	puts("Median Filter!!!!"); /* prints Median Filter */
	printf("Altera LightWeight offset: %X\n", ALT_LWFPGASLVS_OFST);
	printf("On Chip Memory offset: %X\n", ONCHIP_MEMORY_BASE);
	printf("LEDS offset: %X\n", LEDS_BASE);
	printf("On Chip Memory SPAN: %X\n", ONCHIP_MEMORY_SPAN);
	printf("On Chip Memory offset+base: %X\n", (ALT_LWFPGASLVS_OFST + ONCHIP_MEMORY_BASE));

	fd = open("/dev/mem", (O_RDWR | O_SYNC));


	//Map onchip_mem Physical Address to Virtual Address Space
	onchip_mem = mmap( NULL, ONCHIP_MEMORY_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, (ALT_HPS2FPGASLVS_OFST + ONCHIP_MEMORY_BASE) );

	printf(onchip_mem);
	for (i=0; i < 12; i++)
	{
	   *(onchip_mem+i) = 'a';
	   *(onchip_mem+i+1) = '\0';
	   usleep(1000*1000);
	   printf("------------\nchar: %c\n",*onchip_mem);
	   printf(onchip_mem);
	   printf("\n");
	}

	leds =  mmap( NULL, LEDS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, (ALT_HPS2FPGASLVS_OFST + LEDS_BASE) );

	*leds = 0xFF;


	//Unmap
	munmap(onchip_mem, ONCHIP_MEMORY_SPAN);
	munmap(leds, LEDS_SPAN);

	close(fd);
	return(0);
}
