/*
 * To build, use the next instruction on Ubuntu
 * $ sudo apt-get install libpng-dev
 */


#include "./split.h"

Image split_image(Image img, ImgSize out_image_props) {
  Pixelp *out_image_rows = (Pixelp*)malloc(sizeof(Pixelp) * out_image_props.height);
  for(int y = 0; y < out_image_props.height; y++) {
    out_image_rows[y] = (Pixel*)malloc(sizeof(Pixel) * out_image_props.width);
  }

  for(int y = 0; y < out_image_props.height; y++) {
    Pixelp in_row = img.Rows[out_image_props.y + y];
    Pixelp out_row = out_image_rows[y];
    //printf("- Row_in: %d , Row_out: %d\n",out_image_props.y + y, y);
    for(int x = 0; x < out_image_props.width; x++) {
      //printf("** Col_in: %d , Col_out: %d\n",out_image_props.x + x, x);
      Pixel* original_pixel = &(in_row[out_image_props.x + x]); 
      Pixel* new_pixel = &out_row[x];
      memcpy(new_pixel,original_pixel,1);
    }
  }
  Image res = {out_image_rows, out_image_props};
  return res;
}