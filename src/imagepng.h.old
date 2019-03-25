#ifndef IMAGE_PNG_H
#define IMAGE_PNG_H

#include <png.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"


typedef struct {
  png_bytep * Rows;
  ImgSize size;
} PNGImage;


//For initialization
typedef struct 
{
  int width, height;
  png_byte color_type;
  png_byte bit_depth;
} png_props;

void free_image_png(PNGImage);

#endif
