#ifndef IMAGE_PROCESSING__
#define IMAGE_PROCESSING__

// Prototype your functions here

#pragma once

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>

using namespace std;


//Copies data_in to data_Out
void copy( int** data_In, int** data_Out, int height, int width);

//Flips the image vertically
void vertical( int** data_In, int** data_Out, int height, int width);

//Flips the image Horizontally
void horizontal( int** data_In, int** data_Out, int height, int width);

//Applies median filter to image
void medianFilter( int** data_In, int** data_Out, int height, int width, int kernelsize);

// Functions called by medianFilter //
//Swaps two values
void swapValues( int* const a, int* const b);

//Sorts values in array by size
void selectionSort(int* const numbers, const int n);

// Calculates the median of a provided list
int medianwindow(int* list, int length);

//Applies Gaussian Filter (7x7) to image
void gaussianFilter(int** original, int** output, int height, int width);
#endif