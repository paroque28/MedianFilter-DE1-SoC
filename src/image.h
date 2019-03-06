#ifndef IMAGE_H
#define IMAGE_H

#include <png.h>


//For initialization
struct img_props
{
  int width, height;
  png_byte color_type;
  png_byte bit_depth;
};

//For splits
typedef struct {
  int x, y, width, height;
} ImgSize;


typedef struct {
  char r, g, b;
} Pixel;

#endif
