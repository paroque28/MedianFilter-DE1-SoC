#ifndef CONVERT_H
#define CONVERT_H

#include "../image.h"
#include "../imagenios.h"
#include <stdlib.h>
#include <stdio.h>


ImageNIOS convertImageToImageNIOS (Image);
Image convertNIOSImageToImage (ImageNIOS);

#endif    