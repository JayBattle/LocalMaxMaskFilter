/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
runMaxMaskFilter.cpp
Program Description:
This Class defines and image object header
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<iostream>
#include "LocalMaxMaskFilter.h"
using namespace std;

int main(int argc, char *argv[])  {
	int debug = 1;
	
	if( argc > 7 ) {
      printf("Too many arguments supplied.\n");
	  return 0;
	} else if (argc<7) {
      printf("Too few arguments supplied.\n");
	  return 0;
	} else if (argc=7) {
      if (debug>0) printf("The image file selected for Filtering is : %s\n", argv[3]);
	  if (debug>0) printf("The filtered image file is : %s\n", argv[4]);
	  if (debug>0) printf("Image size is %s x %s\n", argv[1], argv[2]);
	  if (debug>0) printf("Filter size is %s x %s\n", argv[5], argv[6]);
	}	
	int NumRows = (float) atof(argv[1]);
	int NumCols = (float) atof(argv[2]);
	int filterLength = (float) atof(argv[5]);
	int filterWidth = (float) atof(argv[6]);
	Image inputImage(NumRows,NumCols);		
	inputImage.ReadImage(argv[3]);		
	if (debug>1) cout<<"Original Image\n";
	if (debug>1) inputImage.PrintImage();		
	LocalMaxMaskFilter TestFilter;
	Image outputImage = TestFilter.Process(inputImage, filterLength, filterWidth);		
	if (debug>1) cout<<"Ouput Image\n";
	if (debug>1) outputImage.PrintImage();		
	outputImage.WriteImage(argv[4]);
	if (debug>0) printf("%s Created\n", argv[4]);
	return 0;
	
}