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

unsigned char get_pixel(Image image,int x, int y){

}
void set_pixel(Image image, int x, int y, unsigned char val){
    
}