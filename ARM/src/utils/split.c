/*
 * To build, use the next instruction on Ubuntu
 * $ sudo apt-get install libpng-dev
 */


#include "./split.h"



PNGImage split_image(png_bytep *in_image_rows, ImgSize out_image_props) {
  png_bytep *out_image_rows = (png_bytep*)malloc(sizeof(png_bytep) * out_image_props.height);
  for(int y = 0; y < out_image_props.height; y++) {
    out_image_rows[y] = (png_byte*)malloc(sizeof(png_bytep) * out_image_props.width);
  }

  for(int y = 0; y < out_image_props.height; y++) {
    png_bytep in_row = in_image_rows[out_image_props.y + y];
    png_bytep out_row = out_image_rows[y];
    //printf("- Row_in: %d , Row_out: %d\n",out_image_props.y + y, y);
    for(int x = 0; x < out_image_props.width; x++) {
      //printf("** Col_in: %d , Col_out: %d\n",out_image_props.x + x, x);
      png_bytep original_pixel = &(in_row[(out_image_props.x + x) * 4]); 
      png_bytep new_pixel = &(out_row[x * 4]);
      memcpy(new_pixel,original_pixel,4);
      png_bytep px = &(out_row[ x * 4]);
      //printf("**** %4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
    }
  }
  PNGImage res = {out_image_rows, out_image_props};
  return res;
}