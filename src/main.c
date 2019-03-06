#include "image.h"
#include "utils/split.h"

int main(int argc, char *argv[]) {
  if(argc != 3){ // argv[1]: image file , argv[2]: percentage
    printf("Not enough arguments!!\n");
    abort();
  }


  // Get Image properties
  float percentage = atof(argv[2])/100.0f;
  struct img_props input_image_props = get_png_props(argv[1]);
  ImgSize input_image_size = {0,0,input_image_props.width, input_image_props.height};
  // Get Matrix from image
  png_bytep * row_pointers = read_png_file(argv[1]);
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
  // NIOS II Cuadrante 4 , ARM 1,2,3

  printf("Width: %d, Height: %d\n",input_image_props.width,input_image_props.height);
  printf("Width: %d + %d, Height: %d + %d\n",width_a,width_b,height_a,height_b);

  ImgSize image_1_props = {0,0,              width_a,height_a};
  ImgSize image_2_props = {width_a,0,        width_b,height_a};
  ImgSize image_3_props = {0,height_a,       width_a,height_b};
  ImgSize image_4_props = {width_a, height_a,width_b,height_b}; 

  png_bytep * img_1 = split_image(row_pointers, image_1_props);
  png_bytep * img_2 = split_image(row_pointers, image_2_props);
  png_bytep * img_3 = split_image(row_pointers, image_3_props);
  png_bytep * img_4 = split_image(row_pointers, image_4_props);

  print_image(image_1_props, img_1);
  
  write_png_file("img_1.png", image_1_props, img_1);
  write_png_file("img_2.png", image_2_props, img_2);
  write_png_file("img_3.png", image_3_props, img_3);
  write_png_file("img_4.png", image_4_props, img_4);


  return 0;
}