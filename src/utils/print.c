#include "print.h"

//Example Print
void print_image(Image image) {
  for(int y = 0; y < image.size.height; y++) {
    Pixelp row = image.Rows[y];
    for(int x = 0; x < image.size.width; x++) {
      Pixel  px = row[x];
      printf("X: %4d, Y: %4d = RGB(%3d, %3d, %3d)\n", x, y, px, px, px);
    }
  }
}
