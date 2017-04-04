/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
LocalmaxMaskFilter.cpp
Program Description:
This Class defines a Local Max Mask Filter object
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<iostream>
using namespace std;
#include "LocalMaxMaskFilter.h"

	int DebugFlag = 0;

	float LocalMaxMaskFilter::UpdatePixel(Image &inputImage, int length, int width) {
		int centerPixel = inputImage.GetVal(length/2,width/2);
		if (DebugFlag) cout << "Center Pixel "<< centerPixel<< "\n";
		for (int currRow=0; currRow < length; currRow++) {
			for (int currCol=0; currCol < width; currCol++) {
				float currPixel = inputImage.GetVal(currRow,currCol);
				if (DebugFlag) cout<<"Input Pixel "<< currPixel<< "\n";
				if (currPixel > centerPixel) return 0;
			}
		}
		return 1;
	}