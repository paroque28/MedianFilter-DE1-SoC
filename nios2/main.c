#include "sys/alt_stdio.h"
#include <system.h>
#include <string.h>
#include "utils/convert.h"
#include "utils/filter.h"
#include "utils/nios_comm.h"
#include "image.h"
void * sdram = (void *) SDRAM_CONTROLLER_BASE + 0x2000;
void * leds =  (void *) LEDS_BASE;


int main()
{ 
  alt_putstr("Median Filter!\n");

  printf("SDRAM Memory offset: %X\n", sdram);
  printf("SDRAM SPAN: %X\n", SDRAM_CONTROLLER_BASE);
//  while(1){

	  printf("NIOS waiting for input image\n");
	  while (*((int*)leds) != IMAGE_SENT_TO_NIOS){
		  //printf("%X\n",*((int*)leds));
		  usleep(100000);
	  }
	  printf("NIOS receiving input image\n");
	  ImageNIOS fromARM = receiveFromSDRAM(sdram,leds,IMAGE_RECEIVED_ON_NIOS);
	  Image fromARMconv = convertNIOSImageToImage(fromARM);
	  printf("NIOS filtering input image\n");
	  Image filtered_img_arm = medianFilter5x5(fromARMconv);
	  printf("NIOS filtered input image\n");
	  ImageNIOS toARM = convertImageToImageNIOS(filtered_img_arm);
	  sendToSDRAM (sdram, leds, IMAGE_SENT_TO_ARM, toARM);
	  printf("NIOS sent output image\n");
//  }
  return 0;
}
