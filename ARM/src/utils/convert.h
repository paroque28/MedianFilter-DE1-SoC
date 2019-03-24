#ifndef CONVERT_H
#define CONVERT_H

#include "../image.h"
#include <stdlib.h>
#include <stdio.h>

Image png_to_Image (PNGImage);    
PNGImage Image_to_png (Image);                

#endif    