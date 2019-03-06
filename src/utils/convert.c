#include "convert.h"

Image png_to_Image (PNGImage image){
    ImgSize props= image.size;
    png_bytep *row_pointers = image.Rows;
    //Reserve memory
    Pixelp * res_rows = (Pixelp*) malloc(sizeof(Pixelp) * props.height);
    for(int y = 0; y < props.height; y++) {
      res_rows[y] = (Pixel *)malloc(sizeof(Pixel) * props.width);
    }

    ImgSize res_size= {0,0,props.width,props.height};
    Image result = {res_rows, res_size};

    for(int y = 0; y < props.height; y++) {
    png_bytep row = row_pointers[y];
    Pixelp res_row = res_rows[y];
    for(int x = 0; x < props.width; x++) {
      png_byte * px = &(row[x * 4]);
      res_row[x].r = px[0];
      res_row[x].g = px[1];
      res_row[x].b = px[2];
      //printf("* %4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
      //printf("+ %4d, %4d = RGB(%3d, %3d, %3d)\n", x, y, result.Rows[y][x].r, result.Rows[y][x].g, result.Rows[y][x].b);
    }
  }
  return result;
}


PNGImage Image_to_png (Image image){
    ImgSize props= image.size;
    Pixelp * row_pointers = image.Rows;
    //Reserve memory
    png_bytep * res_rows = (png_bytep*) malloc(sizeof(png_bytep) * props.height);
    for(int y = 0; y < props.height; y++) {
      res_rows[y] = (png_byte *)malloc(sizeof(png_byte) * props.width);
    }

    ImgSize res_size= {0,0,props.width,props.height};
    Image result = {res_rows, res_size};

    for(int y = 0; y < props.height; y++) {
    Pixel * row = row_pointers[y];
    png_bytep res_row = res_rows[y];
    for(int x = 0; x < props.width; x++) {
      res_row[x] = row[x].r;
      res_row[x+1] = row[x].g;
      res_row[x+2] = row[x].b;
      res_row[x+3] = 255;
    }
  }
  PNGImage res = {res_rows,props};
  return res;
}