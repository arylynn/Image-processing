#include "ImageProcessing.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void copy(int **data_In, int **data_Out, int height, int width) {
  data_Out = data_In;
  
}

//
void vertical(int **data_In, int **data_Out, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      data_Out[height - 1 - i][j] = data_In[i][j];
    }
  }
}

void horizontal(int **data_In, int **data_Out, int height, int width) {
  for (int x = 0; x < height; x++) {
    for (int y = 0; y < width; y++) {
      data_Out[x][width - y - 1] = data_In[x][y];
    }
  }
}

// function called by medianFilter
void swapValues(int *const a, int *const b) {
  int temp_a;
  int temp_b;

  temp_a = *a;
  temp_b = *b;

  *a = temp_b;
  *b = temp_a;
}

// function called by medianFilter
void selectionSort(int *const numbers, const int n) {

  for (int i = 0; i < n - 1; i++) {
    int jMin = i;
    for (int j = i + 1; j < n; j++) {
      if (numbers[j] < numbers[jMin]) {
        jMin = j;
      }
    }

    if (jMin != i) {
      swapValues(&numbers[i], &numbers[jMin]);
    }
  }
}

int medianwindow(int *list, int length) {
  int middle = (length - 1) / 2;
  selectionSort(list, length);
  return list[middle];
}

void medianFilter(int **data_In, int **data_Out, int height, int width,
                  int kernelsize) {
  // buffer on each side of the image
  int buff = (kernelsize - 1) / 2;

  for (int row = buff; row < (height - buff); row++) {
    for (int col = buff; col < (width - buff); col++) {
      // declare list of length (kernelsize)^2 called medianlist
      int medianlist[kernelsize * kernelsize];
      int medianlist_index = 0;

      // fill medianlist with values in kernel window
      for (int i = row - buff; i < row + buff + 1; i++) {
        for (int j = col - buff; j < col + buff + 1; j++) {
          medianlist[medianlist_index] = data_In[i][j];
          medianlist_index = medianlist_index + 1;
        }
      }
      // pass medianlist into medianwindow(medianlist,kernelsize^2)
      // set image_out[row][col]=output from medianwindow
      data_Out[row][col] = medianwindow(medianlist, kernelsize * kernelsize);
    }
  }
}

// Gaussian Filter
void gaussianFilter(int **original, int **output, int height, int width) {
  // Instatiate 7x7 Gaussian Kernal
  double gaussianKernel[7][7] = {0, 0, 1, 2, 1, 0, 0, 0, 3, 13, 22, 13, 3, 0, 1, 13, 59, 97, 59, 13, 1, 2, 22, 97, 159, 97, 22, 2, 1, 13, 59, 97, 59, 13, 1, 0, 3, 13, 22, 13, 3, 0, 0, 0, 1, 2, 1, 0, 0};
  // Declare result that will hold the result of each convolution
  double result;
  // Instantiate buffer to prevent access to image edges
  int buffer = 3;
  // Instatiate "traverseX" and "traverseY" to select each value in the original image array to be multiplied by the kernel for each convolution
  int traverseY = 0;
  int traverseX = 0;
  // BEGIN CONVOLUTION
  // Image Row Iterator
  for (int i = buffer; i < height - buffer; i++) { // Image Column Iterator
    for (int j = buffer; j < width - buffer; j++) {
      result = 0;
      traverseY = 0;
      // Kernel Row Iterator
      for (int k = 0; k < 7; k++) {
        // Kernel Column Iterator
        for (int l = 0; l < 7; l++) {
          result += gaussianKernel[k][l] * original[i - buffer + traverseY][j - buffer + traverseX];
          ++traverseX;
        }
        ++traverseY;
        traverseX = 0;
      }
      output[i][j] = result/1003;
    }
  }
}
