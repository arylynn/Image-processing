#include "PGM.h"
using namespace std;

int main() {
  // Path to the file
  // If image is in the same directory as executable
  // string fileName = "lena.pgm";

  // Clion paths
  // string fileName = "..\\test_images\\lena.pgm";
  // string outputName = "..\\processed_images\\lena_copy.pgm";

  // Paths that work with replit
  string fileName = "test_images/lena.pgm";
  string outputName = "processed_images/lena_copy.pgm";

  // Open File set information
  if (openPGM(fileName)) {
    // Get Image Size Information
    int width = getPGMWidth();
    int height = getPGMHeight();

    // Declare and allocate memory for data
    int **original;
    original = new int *[height];

    for (int i = 0; i < height; i++) {
      original[i] = new int[width];
    }

    // Get the data
    getPGMData(original);

    // Write back out the same image
    writePGM(outputName, original);

    // Clean up memory
    for (int i = 0; i < height; i++) {
      delete[] original[i];
    }
    delete[] original;
  }
}