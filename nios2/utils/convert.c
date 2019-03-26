#include "convert.h"

ImageNIOS convertImageToImageNIOS (Image img){
    PixelNIOS * pixels = malloc(sizeof (PixelNIOS) * img.size.width * img.size.height);

    for(int y = 0; y < img.size.height; y++) {
        memcpy((pixels+(y*img.size.width)),img.Rows[y], img.size.width);
    }

    ImageNIOS result = {img.size.width, img.size.height, pixels};
    return result;
}
Image convertNIOSImageToImage (ImageNIOS img){
    Pixelp * rows = (Pixelp*) malloc(sizeof(Pixelp) * img.height);

    for(int y = 0; y < img.height; y++) {
      rows[y] = (Pixel *)malloc(sizeof(Pixel) * img.width);
    }

    for(int y = 0; y < img.height; y++) {
        memcpy(rows[y],(img.pixels + ( y * img.width )), img.width);
    }



    ImgSize size = {0,0,img.width,img.height};
    Image result = { rows, size };
    return result;
}