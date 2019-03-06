#ifndef SPLIT_H
#define SPLIT_H

#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <string.h>
#include "../image.h"

struct img_props get_png_props(char *filename);
png_bytep * read_png_file(char *filename);
void write_png_file(char *filename, ImgSize props, png_bytep *row_pointers );
void print_image(ImgSize props, png_bytep *row_pointers);
png_bytep * split_image(png_bytep *in_image_rows, ImgSize out_image_props);

#endif