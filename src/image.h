#ifndef IMAGE_H
#define IMAGE_H

#include <png.h>

// Important

//For Matrixes
typedef struct {
  int x, y, width, height;
} ImgSize;

typedef struct {
  unsigned char r, g, b;
} Pixel;

typedef Pixel * Pixelp;

typedef struct {
  Pixelp * Rows;
  ImgSize size;
} Image;



// Important END




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


#endif
