#include "image.h"
// #include "imagepng.h"
#include "imagenios.h"
#include "utils/split.h"
#include "utils/glue.h"
#include "utils/convert.h"
#include "utils/print.h"
#include "utils/filter.h"
#include "utils/nios_comm.h"
#include "math.h"
#include "utils/pgm.h"



Image img_1;
Image img_2;
Image img_3;
Image img_4;

int config_images(char * file, float percentage){

  Image imgRaw = getPGMfile(file);
  //print_image(imgRaw);
  save(imgRaw ,"in.pgm");

  
  
  //Split Images ratios
  printf("Spliting image with percentage %f\n", percentage);
  
 
  int width_a  = imgRaw.size.width*percentage;
  int width_b  = imgRaw.size.width-width_a;
  int height_a = imgRaw.size.height*percentage;
  int height_b = imgRaw.size.height-height_a;

  //      A      B
  //    |------|-----|
  //  A |   1  |  2  |
  //    |------|-----|
  //  B |   3  | *4* |
  //    |------|-----|
  // ** NIOS II Cuadrante 4 , ARM 1,2,3

  printf("Width: %d, Height: %d\n",imgRaw.size.width,imgRaw.size.height);
  printf("Width: %d + %d, Height: %d + %d\n",width_a,width_b,height_a,height_b);

  ImgSize image_1_props = {0,0,              width_a,height_a};
  ImgSize image_2_props = {width_a,0,        width_b,height_a};
  ImgSize image_3_props = {0,height_a,       width_a,height_b};
  ImgSize image_4_props = {width_a, height_a,width_b,height_b}; 

   img_1 = split_image(imgRaw, image_1_props);
   img_2 = split_image(imgRaw, image_2_props);
   img_3 = split_image(imgRaw, image_3_props);
   img_4 = split_image(imgRaw, image_4_props);
}

int main(int argc, char *argv[]) {
  if(argc != 3){ // argv[1]: image file , argv[2]: percentage
    printf("Not enough arguments!!\n");
    abort();
  }

  void * sdram_simulation = malloc((sizeof(int)*2)+(sizeof(char)* 20000000 ));
  int * leds_simulation = malloc(sizeof(int));


  // Get Image properties
  float percentage = atof(argv[2])/100.0f;
  config_images(argv[1], percentage);

  // FILTER ARM IMAGES
  Image filtered_img_1 = medianFilter5x5(img_1);
  Image filtered_img_2 = medianFilter5x5(img_2);
  Image filtered_img_3 = medianFilter5x5(img_3);
  

  // FILTER NIOS IMAGE
  ImageNIOS image_to_nios = convertImageToImageNIOS(img_4);
  //SEND TO NIOS
  sendToSDRAM(sdram_simulation, leds_simulation, IMAGE_SENT_TO_NIOS, image_to_nios);
        //ON NIOS
        while (*leds_simulation != IMAGE_SENT_TO_NIOS);
        ImageNIOS fromARM = receiveFromSDRAM(sdram_simulation,leds_simulation,IMAGE_RECEIVED_ON_NIOS);
        Image fromARMconv = convertNIOSImageToImage(image_to_nios);
        Image filtered_img_arm = medianFilter5x5(fromARMconv);
        ImageNIOS toARM = convertImageToImageNIOS(filtered_img_arm);
        sendToSDRAM (sdram_simulation, leds_simulation, IMAGE_SENT_TO_ARM, toARM);
        //ON NIOS_EXIT
  while (*leds_simulation != IMAGE_SENT_TO_ARM);
  ImageNIOS imagenios_from_nios = receiveFromSDRAM(sdram_simulation, leds_simulation, IMAGE_RECEIVED_ON_ARM); 
  Image filtered_img_4 = convertNIOSImageToImage(imagenios_from_nios); 
 // FILTER NIOS IMAGE END


  // JOIN IMAGES
  Image result = glue_image(filtered_img_1,filtered_img_2,filtered_img_3,filtered_img_4);
  save(result, "result.pgm");
  
  save(img_1,"img_1.pgm");
  save(img_2,"img_2.pgm");
  save(img_3,"img_3.pgm");
  save(img_4,"img_4.pgm");

  return 0;
}