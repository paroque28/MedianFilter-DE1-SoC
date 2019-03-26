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

  while (*((int*)leds) != IMAGE_SENT_TO_NIOS);
  ImageNIOS fromARM = receiveFromSDRAM(sdram,leds,IMAGE_RECEIVED_ON_NIOS);
  Image fromARMconv = convertNIOSImageToImage(fromARM);
  Image filtered_img_arm = medianFilter5x5(fromARMconv);
  ImageNIOS toARM = convertImageToImageNIOS(filtered_img_arm);
  sendToSDRAM (sdram, leds, IMAGE_SENT_TO_ARM, toARM);

  return 0;
}
