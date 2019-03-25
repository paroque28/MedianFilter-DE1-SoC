#ifndef FILTER_H
#define FILTER_H

#include "../image.h"
#include "print.h"

void swap (int *xp, int *yp);
void printArray (int array[], int size);
int Bubblesort_Number (int array[], int size);
Image medianFilter3x3 (Image image);
Image medianFilter5x5 (Image image);

#endif