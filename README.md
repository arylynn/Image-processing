Project I Checker
===
This repl can help you check the result of your image processing methods.

Steps
===
1. Complete or upload all your .cpp and .h files
2. Make sure set CHECK_IMAGES=true in the secrets tab(Lock Symbol in Replit)

   
```json
RAW JSON Input
{
   "CHECK_IMAGES": "true"
}
```

3. testInput.txt is all the input that is entered to your program
4. ***Use Run at top of repl to compare processed images to golden files.***

How Test Works
===
The testInput.txt is used to control your program (file names, save filenames and processing operation). 
The run.bash script uses diff to compare if processed images match the golden images.

Asssumed inputs
===
1. Original image file name
2. Operations
   
      0 - Copy
   
      1 - Vertical Flip
  
      2 - Horizontal Flip
    
      3 - Median Filter

      4 - Median Filter 9x9

      5 - Median Filter 15x15

      6 - Gaussian Filter 7x7
3. Processed image file name
4. Continue y/n