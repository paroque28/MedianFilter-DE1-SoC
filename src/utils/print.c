#include "print.h"


void print_image_png(PNGImage image) {
  ImgSize props= image.size;
  png_bytep *row_pointers = image.Rows;
  for(int y = 0; y < props.height; y++) {
    png_bytep row = row_pointers[y];
    for(int x = 0; x < props.width; x++) {
      png_byte * px = &(row[x * 4]);
      printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);

    }
  }
}

//Example Print
void print_image(Image image) {
  for(int y = 0; y < image.size.height; y++) {
    Pixelp row = image.Rows[y];
    for(int x = 0; x < image.size.width; x++) {
      Pixel  px = row[x];
      printf("%4d, %4d = RGB(%3d, %3d, %3d)\n", x, y, px.r, px.g, px.g);
    }
  }
}