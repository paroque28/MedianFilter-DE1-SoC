#include "imagenios.h"

void freeImageNIOS(ImageNIOS img){
    free (img.pixels);
}