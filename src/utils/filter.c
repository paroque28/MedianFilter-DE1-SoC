#include "filter.h"

void swap (int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
  }


void printArray (int array[], int size){ 
    int i; 

    for (i=0; i < size; i++){
      //printf("%d ", array[i]); 
       
    }
    //printf("\n");
          
}
int Bubblesort_Number (int array[], int size){

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

    if(size % 2 == 0){
    //printf("RESULT NUMBER/S = %d , %d \n",array[(size-2)/2],array[((size-2)/2)+1]);
      return (array[(size-2)/2] + array[((size-2)/2)+1]) / 2;
    }else{
      //printf("RESULT NUMBERS = %d \n",array[(size-1)/2]);
      return array[(size-1)/2];
    }
}

Image medianFilter3x3 (Image image){
    Image cloned_image = clone(image);
    
    
     
    for(int j = 0; j < image.size.height ; j++){ 
      for(int i = 0; i < image.size.width ; i++){ 
        if(j == 0 ){

          if( i == 0){


            int array[] = {image.Rows[j][i], image.Rows[j][i+1] ,image.Rows[j+1][i]  , image.Rows[j+1][i+1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

            


          }else if( i == image.size.width -1){

            int array[] = {image.Rows[j][i] ,image.Rows[j][i-1] ,image.Rows[j+1][i]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);


          }else{

            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1] ,image.Rows[j][i-1]  ,image.Rows[j+1][i]  ,image.Rows[j+1][i+1]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);
            
          }
          
        }else if(j == image.size.height -1){
          if( i == 0){
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1] ,image.Rows[j-1][i]  ,image.Rows[j-1][i+1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);


          }else if( i == image.size.width -1){
            int array[] = {image.Rows[j][i] ,image.Rows[j][i-1] ,image.Rows[j-1][i]  ,image.Rows[j-1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

          }else{
            int array[] = {image.Rows[j][i] ,image.Rows[j][i+1] ,image.Rows[j][i-1] ,image.Rows[j-1][i] ,image.Rows[j-1][i+1] ,image.Rows[j-1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res =  Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);
            
          }


        }else{
          if(i == 0){
            int array[] = {image.Rows[j][i] ,image.Rows[j][i+1] ,image.Rows[j-1][i] ,image.Rows[j-1][i+1] ,image.Rows[j+1][i] ,image.Rows[j+1][i+1]};
            int size = sizeof(array)/sizeof(array[0]);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);


          }else if(i == image.size.width - 1){
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i-1] ,image.Rows[j-1][i] , image.Rows[j-1][i-1] , image.Rows[j+1][i]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

          }else{
            int array[] = {image.Rows[j][i]  ,image.Rows[j][i+1]  ,image.Rows[j][i-1]  , image.Rows[j-1][i],image.Rows[j-1][i+1]  ,image.Rows[j-1][i-1]  , image.Rows[j+1][i]  ,image.Rows[j+1][i+1]  ,image.Rows[j+1][i-1] };
            int size = sizeof(array)/sizeof(array[0]);
            int res = Bubblesort_Number(array , size);

            set_pixel(cloned_image, i, j, res);

            
          }

        }
      }

    }

    /*
    png_image = Image_to_png(cloned_image);


    write_png_file("cloned_filter.png", png_image);
    */
   return cloned_image;


}


Image medianFilter5x5 (Image image){
    Image cloned_image = clone(image);
     
    for(int j = 0; j < image.size.height ; j++){
      for(int i = 0; i < image.size.width ; i++){
        if(j == 0 ){
            if(i == 0){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2]  ,image.Rows[j+1][i], image.Rows[j+2][i], image.Rows[j+1][i+1], image.Rows[j+2][i+2], 
                image.Rows[j+2][i+1], image.Rows[j+1][i+2] };
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);
            
            }else if(i == 1){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j+1][i] , image.Rows[j+1][i+1] , image.Rows[j+1][i+2], 
                image.Rows[j+1][i-1] , image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2], image.Rows[j+2][i-1] };
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);

            }else if( i == image.size.width -1){
                int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2]  ,image.Rows[j+1][i], image.Rows[j+2][i], image.Rows[j+1][i-1], image.Rows[j+2][i-2], 
                image.Rows[j+2][i-1], image.Rows[j+1][i-2] };
                int size = sizeof(array)/sizeof(array[0]);
                int res =  Bubblesort_Number(array , size);


                set_pixel(cloned_image, i, j, res);
            }else if(i == image.size.width -2){
                int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j][i+1], image.Rows[j+1][i] , image.Rows[j+1][i-1] , image.Rows[j+1][i-2], 
                image.Rows[j+1][i+1] , image.Rows[j+2][i], image.Rows[j+2][i-1], image.Rows[j+2][i-2], image.Rows[j+2][i+1]  };
                int size = sizeof(array)/sizeof(array[0]);;
                int res =  Bubblesort_Number(array , size);


                set_pixel(cloned_image, i, j, res);
            }else{
                int array[] = {image.Rows[j][i] , image.Rows[j][i+1], image.Rows[j][i+2] , image.Rows[j][i-1] , image.Rows[j][i-2] , image.Rows[j+1][i] , image.Rows[j+1][i+1],
                image.Rows[j+1][i+2], image.Rows[j+1][i-1], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2], image.Rows[j+2][i-1],
                image.Rows[j+2][i-2] };
                int size = sizeof(array)/sizeof(array[0]);
                int res =  Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);
                
            }
            
        }else if(j == 1){
            if(i == 0){
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j-1][i], image.Rows[j-1][i+1], image.Rows[j-1][i+2], image.Rows[j+1][i],
              image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2]};
              int size = sizeof(array)/sizeof(array[0]);

              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }else if(i == 1){
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j-1][i], image.Rows[j-1][i+1], image.Rows[j-1][i+2],
              image.Rows[j-1][i-1], image.Rows[j+1][i], image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j+1][i-1], image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2],
              image.Rows[j+2][i-1]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);


            }else if(i == image.size.width -1){
              int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j-1][i], image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j+1][i],
              image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j+2][i], image.Rows[j+2][i-1], image.Rows[j+2][i-2]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }else if(i == image.size.width - 2){
              int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j][i+1], image.Rows[j-1][i], image.Rows[j-1][i-1], image.Rows[j-1][i-2],
              image.Rows[j-1][i+1], image.Rows[j+1][i], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j+1][i+1], image.Rows[j+2][i], image.Rows[j+2][i-1], image.Rows[j+2][i-2],
              image.Rows[j+2][i+1]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);
                
            }else{
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j-1][i], image.Rows[j-1][i+1], 
              image.Rows[j-1][i+2], image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j+1][i], image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j+1][i-1],
              image.Rows[j+1][i-2], image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }

        }else if(j == image.size.height -1){
            if( i == 0){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2]  ,image.Rows[j-1][i], image.Rows[j-2][i], image.Rows[j-1][i+1], image.Rows[j-2][i+2], 
                image.Rows[j-2][i+1], image.Rows[j-1][i+2] };
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);


            }else if(i == 1){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j-1][i] , image.Rows[j-1][i+1] , image.Rows[j-1][i+2], 
                image.Rows[j-1][i-1] , image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2], image.Rows[j-2][i-1] };
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);

            }else if( i == image.size.width -1){
                int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2]  ,image.Rows[j-1][i], image.Rows[j-2][i], image.Rows[j-1][i-1], image.Rows[j-2][i-2], 
                image.Rows[j-2][i-1], image.Rows[j-1][i-2]  };
                int size = sizeof(array)/sizeof(array[0]);
                int res =  Bubblesort_Number(array , size);


                set_pixel(cloned_image, i, j, res);

            }else if(i == image.size.width -2){
                int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j][i+1], image.Rows[j-1][i] , image.Rows[j-1][i-1] , image.Rows[j-1][i-2], 
                image.Rows[j-1][i+1] , image.Rows[j-2][i], image.Rows[j-2][i-1], image.Rows[j-2][i-2], image.Rows[j-2][i+1]  };
                int size = sizeof(array)/sizeof(array[0]);
                int res =  Bubblesort_Number(array , size);


                set_pixel(cloned_image, i, j, res);
            }else{
                int array[] = {image.Rows[j][i] , image.Rows[j][i+1], image.Rows[j][i+2] , image.Rows[j][i-1] , image.Rows[j][i-2] , image.Rows[j-1][i] , image.Rows[j-1][i+1],
                image.Rows[j-1][i+2], image.Rows[j-1][i-1], image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2], image.Rows[j-2][i-1],
                image.Rows[j-2][i-2] };
                int size = sizeof(array)/sizeof(array[0]);
                int res =  Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);
                
            }


        }else if(j == image.size.height -2){
            if(i == 0){
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j+1][i], image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j-1][i],
              image.Rows[j-1][i+1], image.Rows[j-1][i+2], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }else if(i == 1){
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j+1][i], image.Rows[j+1][i+1], image.Rows[j+1][i+2],
              image.Rows[j+1][i-1], image.Rows[j-1][i], image.Rows[j-1][i+1], image.Rows[j-1][i+2], image.Rows[j-1][i-1], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2],
              image.Rows[j-2][i-1]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);


            }else if(i == image.size.width -1){
              int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j+1][i], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j-1][i],
              image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j-2][i], image.Rows[j-2][i-1], image.Rows[j-2][i-2]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }else if(i == image.size.width - 2){
              int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j][i+1], image.Rows[j+1][i], image.Rows[j+1][i-1], image.Rows[j+1][i-2],
              image.Rows[j+1][i+1], image.Rows[j-1][i], image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j-1][i+1], image.Rows[j-2][i], image.Rows[j-2][i-1], image.Rows[j-2][i-2],
              image.Rows[j-2][i+1]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);
                
            }else{
              int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j+1][i], image.Rows[j+1][i+1], 
              image.Rows[j+1][i+2], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j-1][i], image.Rows[j-1][i+1], image.Rows[j-1][i+2], image.Rows[j-1][i-1],
              image.Rows[j-1][i-2], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2]};
              int size = sizeof(array)/sizeof(array[0]);
              int res =  Bubblesort_Number(array , size);
              
              
              set_pixel(cloned_image, i, j, res);

            }


        }else{
            if(i == 0){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2],image.Rows[j-1][i] , image.Rows[j-1][i+1], image.Rows[j-1][i+2], image.Rows[j-2][i], 
                image.Rows[j-2][i+1], image.Rows[j-2][i+2], image.Rows[j+1][i], image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j+2][i], image.Rows[j+2][i+1],
                image.Rows[j+2][i+2]};
                int size = sizeof(array)/sizeof(array[0]);

                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);
            }else if(i == 1){
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j-1][i], image.Rows[j-1][i+1], image.Rows[j-1][i+2], 
                image.Rows[j-1][i-1], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2], image.Rows[j-2][i-1], image.Rows[j+1][i], image.Rows[j+1][i+1], 
                image.Rows[j+1][i+2], image.Rows[j+1][i-1], image.Rows[j+2][i], image.Rows[j+2][i+1], image.Rows[j+2][i+2], image.Rows[j+2][i-1]};
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);

            }else if(i == image.size.width - 1){
                int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2],image.Rows[j-1][i] , image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j-2][i], 
                image.Rows[j-2][i-1], image.Rows[j-2][i-2], image.Rows[j+1][i], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j+2][i], image.Rows[j+2][i-1],
                image.Rows[j+2][i-2]};
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);
                set_pixel(cloned_image, i, j, res);

            }else if(i == image.size.width){
              int array[] = {image.Rows[j][i], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j][i+1], image.Rows[j-1][i], image.Rows[j-1][i-1], image.Rows[j-1][i-2], 
                image.Rows[j-1][i+1], image.Rows[j-2][i], image.Rows[j-2][i-1], image.Rows[j-2][i-2], image.Rows[j-2][i+1], image.Rows[j+1][i], image.Rows[j+1][i-1], 
                image.Rows[j+1][i-2], image.Rows[j+1][i+1], image.Rows[j+2][i], image.Rows[j+2][i-1], image.Rows[j+2][i-2], image.Rows[j+2][i+1]};
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);
            }else{
                int array[] = {image.Rows[j][i], image.Rows[j][i+1], image.Rows[j][i+2], image.Rows[j][i-1], image.Rows[j][i-2], image.Rows[j-1][i], image.Rows[j-1][i+1], 
                image.Rows[j-1][i+2], image.Rows[j-1][i-1], image.Rows[j-1][i-2], image.Rows[j-2][i], image.Rows[j-2][i+1], image.Rows[j-2][i+2], image.Rows[j-2][i-1], 
                image.Rows[j-2][i-2], image.Rows[j+1][i] ,image.Rows[j+1][i+1], image.Rows[j+1][i+2], image.Rows[j+1][i-1], image.Rows[j+1][i-2], image.Rows[j+2][i], 
                image.Rows[j+2][i+1], image.Rows[j+2][i+2], image.Rows[j+2][i-1], image.Rows[j+2][i-2]};
                int size = sizeof(array)/sizeof(array[0]);
                int res = Bubblesort_Number(array , size);

                set_pixel(cloned_image, i, j, res);

                
            }

        }
      }
  }
        /*
        png_image = Image_to_png(cloned_image);
        write_png_file("cloned_filter.png", png_image);
        */
       return cloned_image;

}

