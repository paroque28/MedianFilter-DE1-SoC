/*
 * To build, use the next instruction on Ubuntu
 * $ sudo apt-get install libpng-dev
 */


#include "./glue.h"


PNGImage glue_image(PNGImage img1, PNGImage img2, PNGImage img3, PNGImage img4){
/*png_bytep *in_image_rows1, ImgSize in_image_props1, 
png_bytep *in_image_rows2, ImgSize in_image_props2,
png_bytep *in_image_rows3, ImgSize in_image_props3,
png_bytep *in_image_rows4, ImgSize in_image_props4) */

    png_bytep *in_image_rows1 = img1.Rows;
    png_bytep *in_image_rows2 = img2.Rows;
    png_bytep *in_image_rows3 = img3.Rows;
    png_bytep *in_image_rows4 = img4.Rows;

    ImgSize in_image_props1 = img1.size;
    ImgSize in_image_props2 = img2.size;
    ImgSize in_image_props3 = img3.size;
    ImgSize in_image_props4 = img4.size;


    int total_height = in_image_props1.height + in_image_props3.height;
    int total_width = in_image_props1.width + in_image_props2.width;
    int temp_height = 0;
    int temp_width = 0;

    png_bytep *out_image_rows = (png_bytep*)malloc(sizeof(png_bytep) * total_height);

    for(int y = 0; y < total_height; y++) {
        out_image_rows[y] = (png_byte*)malloc(sizeof(png_byte) * total_width*4); //Remember *4
    }
    
    for (int y = 0; y < in_image_props1.height; y++){
        png_bytep in_row = in_image_rows1[y];
        png_bytep out_row = out_image_rows[y];
        for (int x = 0; x < in_image_props1.width; x++){
            png_bytep px_in = &(in_row[x*4]);
            png_bytep px_out = &(out_row[x*4]);
            memcpy (px_out, px_in, 4);
        
        }
    }
    for (int y = 0; y < in_image_props2.height; y++){
        png_bytep in_row = in_image_rows2[y];
        png_bytep out_row = out_image_rows[y];
        for (int x = 0; x < in_image_props2.width; x++){
            png_bytep px_in = &(in_row[x*4]);
            png_bytep px_out = &(out_row[(x+in_image_props1.width)*4]);
            memcpy (px_out, px_in, 4);
        
        }
    }
    for (int y = 0; y < in_image_props3.height; y++){
        png_bytep in_row = in_image_rows3[y];
        png_bytep out_row = out_image_rows[y+in_image_props1.height];
        for (int x = 0; x < in_image_props3.width; x++){
            png_bytep px_in = &(in_row[x*4]);
            png_bytep px_out = &(out_row[x*4]);
            memcpy (px_out, px_in, 4);
        
        }
    }
    for (int y = 0; y < in_image_props4.height; y++){
        png_bytep in_row = in_image_rows4[y];
        png_bytep out_row = out_image_rows[y+in_image_props1.height];
        for (int x = 0; x < in_image_props4.width; x++){
            png_bytep px_in = &(in_row[(x)*4]);
            png_bytep px_out = &(out_row[(x+in_image_props1.width)*4]);
            memcpy (px_out, px_in, 4);
        
        }
    }
    ImgSize out_size = {0,0,total_width,total_height};
    PNGImage res = {out_image_rows, out_size};
    return res;
}