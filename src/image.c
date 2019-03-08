#include "image.h"


void free_image(Image image){
    for(int y = 0; y < image.size.height; y++) {
      free( image.Rows[y]);
    }
    free(image.Rows);
}
void free_image_png(PNGImage image){
    for(int y = 0; y < image.size.height; y++) {
      free( image.Rows[y]);
    }
    free(image.Rows);
}

Pixel get_pixel(Image image,int x, int y){
    return &(image.Rows[y])[x];
}

void set_pixel(Image image, int x, int y, Pixel val){
    &(image.Rows[y])[x] = val;
}