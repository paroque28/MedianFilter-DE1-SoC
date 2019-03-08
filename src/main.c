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





  //print_image(image_matrix);


  // FILTER IMAGE CODE

  void swap (int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
  }

  
  // Function used for print arrays
  void printArray (int array[], int size){ 
    int i; 

    for (i=0; i < size; i++){
      printf("%d ", array[i]); 
       
    }
    printf("\n");
          
  }

  // Bubblesort used for sort the pixels
  int Bubblesort_Number (int array[], int size){
    //printArray(array, size);
    int res;

    int i, j; 
    for (i = 0; i < size-1; i++){
      // Last i elements are already in place    
      for (j = 0; j < size-i-1; j++){
        if (array[j] > array[j+1]){
          swap(&array[j], &array[j+1]);
        } 
      } 
    }

    //printArray(array, size);

    //printf("size = %d \n", size);
    if(size == 9){
      printf("RESULT NUMBERS = %d \n",array[4]);
      return array[4];
    }else if(size == 4){
      printf("RESULT NUMBER/S = %d , %d \n",array[1],array[2]);
      return (array[1] + array[2]) / 2;
    }else if (size == 6){
      printf("RESULT NUMBER/S = %d , %d \n",array[2],array[3]);
      return (array[2] + array[3]) / 2;
    }
  
      
          
  }


  void medianFilter (Image image){

    Image cloned_image = clone(image);
    
    /*
    for(int j = 0; j < image.size.height ; j++){
      for(int i = 0; i < image.size.width ; i++){
        set_pixel(cloned_image, i , j , 0);
      }
    }*/


     
    for(int j = 0; j < image.size.height ; j++){
      //Pixelp row = image.Rows[j];
      
      
      for(int i = 0; i < image.size.width ; i++){
        //Pixel px = row[i];
        
        if(j == 0 ){
          //Pixelp row_down = image.Rows[j+1];
          if( i == 0){
            //Pixel px_right = row[i+1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_right = row_down[i + 1];

            int array[] = {image.Rows[j][i], image.Rows[j][i+1] ,image.Rows[j+1][i]  , image.Rows[j+1][i+1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

            


          }else if( i == image.size.width -1){
            //Pixel px_left = row[i-1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_left = row_down[i-1];
            int array[] = {image.Rows[j][i] ,image.Rows[j][i-1] ,image.Rows[j+1][i]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res =  Bubblesort_Number(array , size);


            set_pixel(cloned_image, i, j, res);


          }else{
            //Pixel px_right = row[i+1];
            //Pixel px_left = row[i-1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_right = row_down[i + 1];
            //Pixel px_down_left = row_down[i + 1];
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1] ,image.Rows[j][i-1]  ,image.Rows[j+1][i]  ,image.Rows[j+1][i+1]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);
            
          }
          
        }else if(j == image.size.height -1){
          //Pixelp row_up = image.Rows[j-1];


          if( i == 0){
            //Pixel px_right = row[i+1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_right = row_up[i + 1];
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1] ,image.Rows[j-1][i]  ,image.Rows[j-1][i+1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);


          }else if( i == image.size.width -1){
            //Pixel px_left = row[i-1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_left = row_up[i-1];
            int array[] = {image.Rows[j][i] ,image.Rows[j][i-1] ,image.Rows[j-1][i]  ,image.Rows[j-1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

          }else{
            //Pixel px_right = row[i+1];
            //Pixel px_left = row[i-1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_right = row_up[i + 1];
            //Pixel px_up_left = row_up[i + 1];
            int array[] = {image.Rows[j][i] ,image.Rows[j][i+1] ,image.Rows[j][i-1] ,image.Rows[j-1][i] ,image.Rows[j-1][i+1] ,image.Rows[j-1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);
            
          }


        }else{
          //Pixelp row_up = image.Rows[j-1];
          //Pixelp row_down = image.Rows[j+1];

          if(i == 0){
            //Pixel px_right = row[i+1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_right = row_up[i + 1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_right = row_down[i + 1];
            int array[] = {image.Rows[j][i] ,image.Rows[j][i+1] ,image.Rows[j-1][i] ,image.Rows[j-1][i+1] ,image.Rows[j+1][i] ,image.Rows[j+1][i+1]};
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);


          }else if(i == image.size.width - 1){
            //Pixel px_left = row[i-1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_left = row_up[i-1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_left = row_down[i-1];
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i-1] ,image.Rows[j-1][i] , image.Rows[j-1][i-1] , image.Rows[j+1][i]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

          }else{
            //Pixel px_right = row[i+1];
            //Pixel px_left = row[i-1];
            //Pixel px_up = row_up[i];
            //Pixel px_up_left = row_up[i-1];
            //Pixel px_up_right = row_up[i+1];
            //Pixel px_down = row_down[i];
            //Pixel px_down_left = row_down[i-1];
            //Pixel px_down_right = row_down[i+1];
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1]  ,image.Rows[j][i-1]  , image.Rows[j-1][i],image.Rows[j-1][i+1]  ,image.Rows[j-1][i-1]  , image.Rows[j+1][i]  ,image.Rows[j+1][i+1]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            printArray(array,size);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

            
          }

        }
        
        //printf("I: %4d, J: %4d = RGB(%3d, %3d, %3d)\n", i, j, px.r, px.g, px.b);
      }

    }


    png_image = Image_to_png(cloned_image);


    write_png_file("cloned_filter.png", png_image);


  }

  medianFilter(image_matrix);

  //int array[] = {90 , 40 , 45 , 60};
  //int size = sizeof(array)/sizeof(array[0]);

  //int a = Bubblesort_Number(array, size);

  //printf("%d\n", a);

  


  //free(image_matrix.Rows);
  //png_image = Image_to_png(cloned_image);


  //write_png_file("result.png", png_image);

  return 0;
}