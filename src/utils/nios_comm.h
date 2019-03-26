#ifndef NIOS_COMM_H
#define NIOS_COMM_H

#include "../imagenios.h"
#include <stdio.h>


#define IMAGE_SENT_TO_NIOS 0xBB
#define IMAGE_SENT_TO_ARM 0xFF
#define IMAGE_RECEIVED_ON_NIOS 0xAA
#define IMAGE_RECEIVED_ON_ARM 0xCC
#define IMAGE_RESET 0x00

void sendToSDRAM(void* sdram, int* leds, int signal, ImageNIOS image);

ImageNIOS receiveFromSDRAM(void* sdram, int* leds, int signal);

#endif