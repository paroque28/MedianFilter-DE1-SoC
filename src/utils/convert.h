#ifndef CONVERT_H
#define CONVERT_H

#include "../image.h"
#include "../imagepng.h"
#include "../imagenios.h"
#include <stdlib.h>
#include <stdio.h>

Image png_to_Image (PNGImage);    
PNGImage Image_to_png (Image);   

ImageNIOS convertImageToImageNIOS (Image);
Image convertNIOSImageToImage (ImageNIOS);

#endif    