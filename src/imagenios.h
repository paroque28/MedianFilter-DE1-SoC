#ifndef IMAGE_NIOS_H
#define IMAGE_NIOS_H

#include "image.h"

//Structs

typedef unsigned char PixelNIOS;

typedef struct {
  unsigned int width;
  unsigned int height;
  PixelNIOS * pixels;
} ImageNIOS;


//Functions

void freeImageNIOS(ImageNIOS);

#endif