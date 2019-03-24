#ifndef NIOS_COMM_H
#define NIOS_COMM_H

#include "../imagenios.h"

void sendToSDRAM(void* sdram, ImageNIOS image);

ImageNIOS receiveFromSDRAM(void* sdram);

#endif