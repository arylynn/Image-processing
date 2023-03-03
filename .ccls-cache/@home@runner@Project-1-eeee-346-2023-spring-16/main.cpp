#include "ImageProcessing.h"
#include "PGM.h"
using namespace std;

char repeat;
int main() {
  do{
  // Path to the file
  // If image is in the same directory as executable
  // string fileName = "lena.pgm";

  // Clion paths
  // string fileName = "..\\test_images\\lena.pgm";
  // string outputName = "..\\processed_images\\lena_copy.pgm";

  // Paths that work with replit
  string fileName = "test_images/lena.pgm";
  string outputName = "processed_images/lena_copy.pgm";
  // string fileName;
  // string outputName;

  cout << "Enter Original File Name:" << endl;
  cin >> fileName;

  // Open File set information
  if (openPGM(fileName)) {
    // Get Image Size Information
    int width = getPGMWidth();
    int height = getPGMHeight();

    // Declare and allocate memory for data
    int **original;
    original = new int *[height];

    int **output;
    output = new int *[height];

    for (int i = 0; i < height; i++) {
      original[i] = new int[width];
      output[i] = new int[width];
    }

    // Get the data
    getPGMData(original);
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        output[i][j] = original[i][j];
      }
    }
    cout << "Select Operation:" << endl
         << "   (0)Copy" << endl
         << "   (1)Flip Veritcal" << endl
         << "   (2)Flip Horizontal" << endl
         << "   (3)3x3 Median Filter" << endl
         << "   (4)9x9 Median Filter" << endl
         << "   (5)15x15 Median Filter" << endl
         << "   (6)7x7 Gaussian Filter" << endl;

    cout << "Enter Selection:";
    int operation;
    cin >> operation;
    cout << "\nPlease enter an outputName:" << endl;
    cin >> outputName;

    int kernelsize;
    // Write back out the same image
    //    writePGM(outputName, output);
    switch (operation) {
    case 0:
      cout << "Copying Image..." << endl;
      copy(original, output, height, width);
      cout << "Writing the file." << endl;
      // writePGM(outputName, output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 1:
      cout << "Flipping Image Vertically..." << endl;
      vertical(original, output, height, width);
      cout << "Writing the file." << endl;
      // writePGM(outputName, output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 2:
      // flipHorizontal( )
      cout << "Flipping Image Horizontally" << endl;
      horizontal(original, output, height, width);
      cout << "Writing the file." << endl;
      // writePGM(outputName,output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 3:
      // 3x3 Median Filter
      cout << "Executing 3x3 Median Filter..." << endl;
      kernelsize = 3;
      medianFilter(original, output, height, width, kernelsize);
      cout << "Writing the file." << endl;
      // writePGM(outputName, output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 4:
      // 9x9 Median Filter
      cout << "Executing 9x9 Median Filter..." << endl;
      kernelsize = 9;
      medianFilter(original, output, height, width, kernelsize);
      cout << "Writing the file." << endl;
      // writePGM(outputName, output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 5:
      // 15x15 Median Filter
      cout << "Executing 15x15 Median Filter..." << endl;
      kernelsize = 15;
      medianFilter(original, output, height, width, kernelsize);
      cout << "Writing the file." << endl;
      // writePGM(outputName, output);
      // if( !writePGM(outputName, output) ){
      //     cout << "Failed to write out file\n";
      // }
      // else
      // {
      //   cout << "File written.\n";
      // }
      break;
    case 6:
      cout << "Executing 7x7 Gaussian Filter..." << endl;
      gaussianFilter(original, output, height, width);
      cout << "Writing the file." << endl;
      break;

    default:
      cout << "Please Try Again";
      break;
    }
    if (writePGM(outputName, output)) {
      cout << "File written successfully.\n";
    } else {
      cout << "Failed to write out file";
    }
    // // Clean up memory
    // for (int i = 0; i < height; i++) {
    //   delete[] original[i];
    // }
    // delete[] original;

    cout << "Cleaning up now." << endl;
    // Clean up memory
    for (int i = 0; i < height; i++) {
      delete[] original[i];
      delete[] output[i];
    }
    delete[] original;
    delete[] output;
    cout << "Clean-up complete." << endl;
  } else {
    cout << "Cannot open file " << fileName << endl;
  }

  cout << "Continue? y/n \n\n" << endl;
  cin >> repeat;
    }
  while (repeat == 'y' || repeat == 'Y');
}