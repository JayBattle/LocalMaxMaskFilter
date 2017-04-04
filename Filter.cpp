/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
Filter.cpp
Program Description:
This Class defines and Filter object
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<iostream>
using namespace std;
#include "Filter.h"

	int Debug = 0;
	
	float Filter::UpdatePixel(Image &inputImage, int length, int width) {
		cout<<"Not Implemented!\n";
		return -1;
	}
	
	Image Filter::Process(Image &inputImage, int length, int width) {
		if ( length % 2 == 0) {
			cout<<"length is not odd\n";
			exit(0);
		} else if ( width % 2 == 0) {
			cout<<"width is not odd\n";
			exit(0);
		}
		Image outputImage = inputImage;
		int borderLength = ((length - 1)/2);
		int borderWidth = ((width - 1)/2); 
		int pixelCount = (inputImage.getNumRows() * inputImage.getNumCols());
		for (int currRow=0; currRow < inputImage.getNumRows(); currRow++) {
			for (int currCol=0; currCol < inputImage.getNumCols(); currCol++) {
				float currPixel = inputImage.GetVal(currRow,currCol);
				if (Debug) cout<<"Current Input Pixel "<<currPixel << "\n";
				if (currRow<borderLength || currCol < borderWidth) outputImage.SetVal(currRow,currCol,0);
				else if (currRow>(inputImage.getNumRows()-borderLength-1)) outputImage.SetVal(currRow,currCol,0);
				else if (currCol>(inputImage.getNumCols()-borderWidth-1)) outputImage.SetVal(currRow,currCol,0);
				else {
					if (Debug) cout<<"Filter Pixel: "<<currPixel<<"\n";
					Image imageSegment(length,width);
					int OuputRow = 0;
					int OuputCol = 0;
					for (int segmentRow=(currRow-borderLength); segmentRow <= (currRow+borderLength); segmentRow++) {
						for (int segmentCol=(currCol-borderWidth); segmentCol <= (currCol+borderWidth); segmentCol++) {
							float newPixel = inputImage.GetVal(segmentRow,segmentCol);
							imageSegment.SetVal(OuputRow,OuputCol, newPixel);
							if (Debug) cout<<"Neighborhood Pixel "<<newPixel<<"\n";
							OuputRow++; 
						}
						OuputRow = 0;
						OuputCol++;
					}
					float updatedPixel = UpdatePixel(imageSegment, length, width);
					if (Debug) cout<<"Updated Pixel "<<updatedPixel<<"\n";
					outputImage.SetVal(currRow,currCol,updatedPixel);
				}
				if (Debug) cout<<"Filtered Pixel: "<<outputImage.GetVal(currRow,currCol)<<"\n";				
			}			
		}				
		return outputImage;
	}
	
	
	
	