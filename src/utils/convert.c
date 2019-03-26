<<<<<<< HEAD
#include "convert_nios.h"
=======
#include "convert.h"



// Image png_to_Image (PNGImage image){
//     ImgSize props= image.size;
//     png_bytep *row_pointers = image.Rows;
//     //Reserve memory
//     Pixelp * res_rows = (Pixelp*) malloc(sizeof(Pixelp) * props.height);
//     for(int y = 0; y < props.height; y++) {
//       res_rows[y] = (Pixel *)malloc(sizeof(Pixel) * props.width);
//     }

//     ImgSize res_size= {0,0,props.width,props.height};
//     Image result = {res_rows, res_size};

//     for(int y = 0; y < props.height; y++) {
//     png_bytep row = row_pointers[y];
//     Pixelp res_row = res_rows[y];
//     for(int x = 0; x < props.width; x++) {
//       png_byte * px = &(row[x * 4]);
//       res_row[x] = (px[0] + px[1] + px[2]) / 3;
//     }
//   }
//   return result;
// }


// PNGImage Image_to_png (Image image){
//     ImgSize props= image.size;
//     Pixelp * row_pointers = image.Rows;
//     //Reserve memory
//     png_bytep * res_rows = (png_bytep*) malloc(sizeof(png_bytep) * props.height);
//     for(int y = 0; y < props.height; y++) {
//       res_rows[y] = (png_byte *)malloc(sizeof(png_byte) * props.width*4);
//     }

//     ImgSize res_size= {0,0,props.width,props.height};
//     PNGImage result = {res_rows, res_size};

//     for(int y = 0; y < props.height; y++) {
//     Pixel * row = row_pointers[y];
//     png_bytep res_row = res_rows[y];
//     for(int x = 0; x < props.width; x++) {
//       png_bytep px = &(res_row[x*4]);
//       px[0] = row[x];
//       px[1] = row[x];
//       px[2] = row[x];
//       px[3] = 255;
//     }
//   }
//   return result;
// }


>>>>>>> e1587680db274f50bac8c66c887053779dc501fd

ImageNIOS convertImageToImageNIOS (Image img){
    PixelNIOS * pixels = malloc(sizeof (PixelNIOS) * img.size.width * img.size.height);

    for(int y = 0; y < img.size.height; y++) {
        memcpy((pixels+(y*img.size.width)),img.Rows[y], img.size.width);
    }

    ImageNIOS result = {img.size.width, img.size.height, pixels};
    return result;
}
Image convertNIOSImageToImage (ImageNIOS img){
    Pixelp * rows = (Pixelp*) malloc(sizeof(Pixelp) * img.height);

    for(int y = 0; y < img.height; y++) {
      rows[y] = (Pixel *)malloc(sizeof(Pixel) * img.width);
    }

    for(int y = 0; y < img.height; y++) {
        memcpy(rows[y],(img.pixels + ( y * img.width )), img.width);
    }



    ImgSize size = {0,0,img.width,img.height};
    Image result = { rows, size };
    return result;
}
<<<<<<< HEAD
=======

>>>>>>> e1587680db274f50bac8c66c887053779dc501fd
