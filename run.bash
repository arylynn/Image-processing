
clang++ -pthread -std=c++17 -o main *.cpp
#Sorting.cpp

if [ $CHECK_IMAGES = true ]; then
  cat testInput.txt | ./main
  echo "Checking Images"
  if [ -f "processed_images/lena_copy.pgm" ]; then
    COPY_CHECK=$(diff -b -B processed_images/lena_copy.pgm processed_golden/lena_copy.pgm)
    if [ "$COPY_CHECK" !=  "" ]; then
      echo "IMAGE COPY - FAIL"
    else
      echo "IMAGE COPY - PASS"
    fi
  else
    echo "IMAGE COPY - FAIL (Missing File)"
  fi

  if [ -f "processed_images/balloons_horz.pgm" ]; then
    HORZ_CHECK=$(diff -b -B processed_images/balloons_horz.pgm processed_golden/balloons_horz.pgm)
    if [ "$HORZ_CHECK" !=  "" ]; then
      echo "IMAGE HORIZONTAL FLIP - FAIL"
    else
      echo "IMAGE HORIZONTAL FLIP - PASS"
    fi 
  else
    echo "IMAGE HORIZONTAL FLIP - FAIL (MISSING FILE)"
  fi

  if [ -f "processed_images/peppers_vert.pgm" ]; then
    VERT_CHECK=$(diff -b -B processed_images/peppers_vert.pgm processed_golden/peppers_vert.pgm)
    if [ "$VERT_CHECK" !=  "" ]; then
      echo "IMAGE VERTICAL FLIP - FAIL"
    else
      echo "IMAGE VERTICAL FLIP - PASS"
    fi
  else
    echo "IMAGE VERTICAL FLIP - FAIL (MISSING FILE)"
  fi

  if [ -f "processed_images/median3.pgm" ]; then
    MEDIAN3_CHECK=$(diff -b -B processed_images/median3.pgm processed_golden/median3.pgm)
    if [ "$MEDIAN3_CHECK" !=  "" ]; then
      echo "IMAGE MEDIAN 3x3 FILTER - FAIL"
    else
      echo "IMAGE MEDIAN 3x3 FILTER - PASS"
    fi
  else
    echo "IMAGE MEDIAN 3x3 FILTER - FAIL (MISSING FILE)"
  fi

  if [ -f "processed_images/median9.pgm" ]; then
    MEDIAN9_CHECK=$(diff -b -B processed_images/median9.pgm processed_golden/median9.pgm)
    if [ "$MEDIAN9_CHECK" !=  "" ]; then
      echo "IMAGE MEDIAN 9x9 FILTER - FAIL"
    else
      echo "IMAGE MEDIAN 9x9 FILTER - PASS"
    fi
  else
    echo "IMAGE MEDIAN 9x9 FILTER - FAIL (MISSING FILE)"
  fi

  if [ -f "processed_images/median15.pgm" ]; then
    MEDIAN15_CHECK=$(diff -b -B processed_images/median15.pgm processed_golden/median15.pgm)
    if [ "$MEDIAN15_CHECK" !=  "" ]; then
      echo "IMAGE MEDIAN 15x15 FILTER - FAIL"
    else
      echo "IMAGE MEDIAN 15x15 FILTER - PASS"
    fi
  else
    echo "IMAGE MEDIAN 15x15 FILTER - FAIL (MISSING FILE)"
  fi
  if [ -f "processed_images/gaussian.pgm" ]; then
    GAUSSIAN_CHECK=$(diff -b -B processed_images/gaussian.pgm processed_golden/gaussian.pgm)
    if [ "$GAUSSIAN_CHECK" !=  "" ]; then
      echo "IMAGE GAUSSIAN FILTER - FAIL"
    else
      echo "IMAGE GAUSSIAN FILTER - PASS"
    fi
  else
    echo "IMAGE GAUSSIAN FILTER - FAIL (MISSING FILE)"
  fi
else
  ./main
fi