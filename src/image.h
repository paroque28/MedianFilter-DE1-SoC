#ifndef IMAGE_H
#define IMAGE_H

#include <png.h>
#include <stdlib.h>

// Important

//For Matrixes
typedef struct {
  int x, y, width, height;
} ImgSize;

typedef unsigned char Pixel;

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

void free_image(Image);
void free_image_png(PNGImage);

unsigned char get_pixel(Image,int x, int y);
void set_pixel(Image, int x, int y, unsigned char val);

#endif
