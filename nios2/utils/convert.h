#ifndef CONVERT_H
#define CONVERT_H

#include "../image.h"
<<<<<<< HEAD:nios2/utils/convert.h
=======
// #include "../imagepng.h"
#include "pgm.h"
>>>>>>> e1587680db274f50bac8c66c887053779dc501fd:src/utils/convert.h
#include "../imagenios.h"
#include <stdlib.h>
#include <stdio.h>

<<<<<<< HEAD:nios2/utils/convert.h
=======
// Image png_to_Image (PNGImage);    
// PNGImage Image_to_png (Image);   
>>>>>>> e1587680db274f50bac8c66c887053779dc501fd:src/utils/convert.h

ImageNIOS convertImageToImageNIOS (Image);
Image convertNIOSImageToImage (ImageNIOS);

#endif    