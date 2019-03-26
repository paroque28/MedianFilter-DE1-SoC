#include "imagepng.h"

void free_image_png(PNGImage image){
    for(int y = 0; y < image.size.height; y++) {
      free( image.Rows[y]);
    }
    free(image.Rows);
}