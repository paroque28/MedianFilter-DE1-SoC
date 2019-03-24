#ifndef SPLIT_H
#define SPLIT_H

#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <string.h>
#include "../image.h"

PNGImage split_image(png_bytep *in_image_rows, ImgSize out_image_props);

#endif