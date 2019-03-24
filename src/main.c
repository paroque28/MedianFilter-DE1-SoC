#include "image.h"
#include "utils/split.h"
#include "utils/glue.h"
#include "utils/convert.h"
#include "utils/print.h"
#include "utils/io.h"
#include "utils/filter.h"
#include "math.h"



PNGImage img_1;
PNGImage img_2;
PNGImage img_3;
PNGImage img_4;

int config_images(char * file, float percentage){
  png_props input_image_props = get_png_props(file);
  ImgSize input_image_size = {0,0,input_image_props.width, input_image_props.height};
  // Get Matrix from image
  png_bytep * row_pointers = read_png_file(file);
  //print_image(input_image_props, row_pointers);


 
  
  //Split Images ratios
  printf("Spliting image with percentage %f\n", percentage);
  
 
  int width_a  = input_image_props.width*percentage;
  int width_b  = input_image_props.width-width_a;
  int height_a = input_image_props.height*percentage;
  int height_b = input_image_props.height-height_a;

  //      A      B
  //    |------|-----|
  //  A |   1  |  2  |
  //    |------|-----|
  //  B |   3  | *4* |
  //    |------|-----|
  // ** NIOS II Cuadrante 4 , ARM 1,2,3

  printf("Width: %d, Height: %d\n",input_image_props.width,input_image_props.height);
  printf("Width: %d + %d, Height: %d + %d\n",width_a,width_b,height_a,height_b);

  ImgSize image_1_props = {0,0,              width_a,height_a};
  ImgSize image_2_props = {width_a,0,        width_b,height_a};
  ImgSize image_3_props = {0,height_a,       width_a,height_b};
  ImgSize image_4_props = {width_a, height_a,width_b,height_b}; 

  img_1 = split_image(row_pointers, image_1_props);
  img_2 = split_image(row_pointers, image_2_props);
  img_3 = split_image(row_pointers, image_3_props);
  img_4 = split_image(row_pointers, image_4_props);
}

int main(int argc, char *argv[]) {
  if(argc != 3){ // argv[1]: image file , argv[2]: percentage
    printf("Not enough arguments!!\n");
    abort();
  }


  // Get Image properties
  float percentage = atof(argv[2])/100.0f;
  config_images(argv[1], percentage);

  // FILTER ARM IMAGES

  Image timg_1 = png_to_Image(img_1);
  Image filtered_img_1 = medianFilter5x5(timg_1);
  PNGImage png_filtered_img_1 = Image_to_png(filtered_img_1);

  Image timg_2 = png_to_Image(img_2);
  Image filtered_img_2 = medianFilter5x5(timg_2);
  PNGImage png_filtered_img_2 = Image_to_png(filtered_img_2);
  
  Image timg_3 = png_to_Image(img_3);
  Image filtered_img_3 = medianFilter5x5(timg_3);
  PNGImage png_filtered_img_3 = Image_to_png(filtered_img_3);
  

  // FILTER NIOS IMAGE

  // Image timg_4 = png_to_Image(img_4);
  // Image filtered_img_4 = medianFilter5x5(timg_4);
  // PNGImage png_filtered_img_4 = Image_to_png(filtered_img_4);
  

  // JOIN IMAGES
  PNGImage result = glue_image(png_filtered_img_1,png_filtered_img_2,png_filtered_img_3,img_4);

  Image img_one = png_to_Image(img_1);
  Image img_one_clone = clone(img_one);
  PNGImage img_revert = Image_to_png(img_one_clone);
  write_png_file("revert.png", img_revert);
  
  write_png_file("img_1.png", img_1);
  write_png_file("img_2.png", img_2);
  write_png_file("img_3.png", img_3);
  write_png_file("img_4.png", img_4);

  write_png_file("result.png", result);

  return 0;
}