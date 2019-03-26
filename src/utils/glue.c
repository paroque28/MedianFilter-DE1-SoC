#include "./glue.h"


Image glue_image(Image img1, Image img2, Image img3, Image img4){

    Pixelp *in_image_rows1 = img1.Rows;
    Pixelp *in_image_rows2 = img2.Rows;
    Pixelp *in_image_rows3 = img3.Rows;
    Pixelp *in_image_rows4 = img4.Rows;

    ImgSize in_image_props1 = img1.size;
    ImgSize in_image_props2 = img2.size;
    ImgSize in_image_props3 = img3.size;
    ImgSize in_image_props4 = img4.size;


    int total_height = in_image_props1.height + in_image_props3.height;
    int total_width = in_image_props1.width + in_image_props2.width;
    int temp_height = 0;
    int temp_width = 0;

    Pixelp *out_image_rows = (Pixelp*)malloc(sizeof(Pixelp) * total_height);

    for(int y = 0; y < total_height; y++) {
        out_image_rows[y] = (Pixelp)malloc(sizeof(Pixel) * total_width);
    }
    
    for (int y = 0; y < in_image_props1.height; y++){
        Pixelp in_row = in_image_rows1[y];
        Pixelp out_row = out_image_rows[y];
        for (int x = 0; x < in_image_props1.width; x++){
            Pixelp px_in = &(in_row[x]);
            Pixelp px_out = &(out_row[x]);
            memcpy (px_out, px_in, 1);
        
        }
    }
    for (int y = 0; y < in_image_props2.height; y++){
        Pixelp in_row = in_image_rows2[y];
        Pixelp out_row = out_image_rows[y];
        for (int x = 0; x < in_image_props2.width; x++){
            Pixelp px_in = &(in_row[x]);
            Pixelp px_out = &(out_row[(x+in_image_props1.width)]);
            memcpy (px_out, px_in, 1);
        
        }
    }
    for (int y = 0; y < in_image_props3.height; y++){
        Pixelp in_row = in_image_rows3[y];
        Pixelp out_row = out_image_rows[y+in_image_props1.height];
        for (int x = 0; x < in_image_props3.width; x++){
            Pixelp px_in = &(in_row[x]);
            Pixelp px_out = &(out_row[x]);
            memcpy (px_out, px_in, 1);
        
        }
    }
    for (int y = 0; y < in_image_props4.height; y++){
        Pixelp in_row = in_image_rows4[y];
        Pixelp out_row = out_image_rows[y+in_image_props1.height];
        for (int x = 0; x < in_image_props4.width; x++){
            Pixelp px_in = &(in_row[(x)]);
            Pixelp px_out = &(out_row[(x+in_image_props1.width)]);
            memcpy (px_out, px_in, 1);
        
        }
    }
    ImgSize out_size = {0,0,total_width,total_height};
    Image res = {out_image_rows, out_size};
    return res;
}