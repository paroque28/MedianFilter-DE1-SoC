#include "image.h"

void set_pixel(Image image, int x, int y, Pixel val){
    image.Rows[y][x] = val;
}

Image clone(Image image){
    //Reserve memory
    Pixelp * res_rows = (Pixelp*) malloc(sizeof(Pixelp) * image.size.height);
    for(int y = 0; y < image.size.height; y++) {
      res_rows[y] = (Pixel *)malloc(sizeof(Pixel) * image.size.width);
    }

    for(int y = 0; y < image.size.height; y++) {
        memcpy(res_rows[y],image.Rows[y], image.size.width);
    }

    Image result = {res_rows, image.size};
    return result;
}
