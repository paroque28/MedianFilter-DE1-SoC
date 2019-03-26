#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>
#include <string.h>


//Structs

typedef struct {
  int x, y, width, height;
} ImgSize;

typedef unsigned char Pixel;

typedef Pixel * Pixelp;

typedef struct {
  Pixelp * Rows;
  ImgSize size;
} Image;


//Functions

void set_pixel(Image, int x, int y, unsigned char val);

Image clone(Image image);

#endif
