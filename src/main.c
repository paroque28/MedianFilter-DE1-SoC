#include "image.h"
#include "utils/split.h"
#include "utils/convert.h"
#include "utils/print.h"
#include "utils/io.h"
#include "utils/filter.h"




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





  //print_image(image_matrix);


  // FILTER IMAGE CODE



  Image img1 = medianFilter3x3(image_matrix);
  png_image = Image_to_png(img1);
  write_png_file("3x3.png", png_image);
  
  Image img2 = medianFilter5x5(image_matrix);
  png_image = Image_to_png(img2);
  write_png_file("5x5.png", png_image);



  //int array[] = {90 , 40 , 45 , 60};
  //int size = sizeof(array)/sizeof(array[0]);

  //int a = Bubblesort_Number(array, size);

  //printf("%d\n", a);

  


  //free(image_matrix.Rows);
  //png_image = Image_to_png(cloned_image);


  //write_png_file("result.png", png_image);

  return 0;
}