#include "image.h"
#include "utils/split.h"
#include "utils/convert.h"
#include "utils/print.h"
#include "utils/io.h"


int main(int argc, char *argv[]) {
  if(argc != 2){ // argv[1]: image file , argv[2]: percentage
    printf("Not enough arguments!!\n");
    abort();
  }

  // Get Image properties
  png_props input_image_props = get_png_props(argv[1]);
  ImgSize input_image_size = {0,0,input_image_props.width, input_image_props.height};
  // Get Matrix from image
  PNGImage png_image = {read_png_file(argv[1]), input_image_size};

  Image image_matrix = png_to_Image(png_image);





  print_image(image_matrix);
  //Filter IMAGE code






  free(image_matrix.Rows);
  png_image = Image_to_png(image_matrix);


  write_png_file("result.png", png_image);

  return 0;
}