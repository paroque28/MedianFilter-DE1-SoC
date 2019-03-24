#include "nios_comm.h"

void sendToSDRAM(void* sdram , int* leds , int signal, ImageNIOS image){
    int * width =  (int * ) sdram;
    int * height =  ((int * ) sdram ) + 1;
    char * pixels = (char *)  (((int * ) sdram ) + 2 );
    * width = image.width;
    * height = image.height;
    memcpy (pixels, image.pixels, image.width * image.height);
    *leds = signal;
    printf("%X\n",*leds);
}

ImageNIOS receiveFromSDRAM(void* sdram, int* leds, int signal){
    int * width =  (int * ) sdram;
    int * height =  ((int * ) sdram ) + 1;
    char * pixels = (char *)  (((int * ) sdram ) + 2 );
    PixelNIOS * pixels_res = malloc(sizeof(PixelNIOS) * *width * *height);
    memcpy (pixels_res, pixels, *width * *height);

    ImageNIOS result = {*width, * height, pixels_res};
    *leds = signal;
    printf("%X\n",*leds);
    return result;

}