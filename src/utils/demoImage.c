#include "demoImage.h"

Image black_and_white (Image image){
    Image cloned_image = clone(image);

    for(int j = 0; j < image.size.height ; j++){
        for(int i = 0; i < image.size.width ; i++){
            if(j % 2 == 0){
                if(i % 2 == 0){
                    set_pixel(cloned_image, i, j, 0);
                }else{
                    set_pixel(cloned_image, i, j, 255);
                }
            }else{
                if(i % 2 == 0){
                    set_pixel(cloned_image, i, j, 255);
                    
                }else{
                    set_pixel(cloned_image, i, j, 0);
                }
            }
        }
    }

    return cloned_image;

}