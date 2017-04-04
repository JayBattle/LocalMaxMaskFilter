/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
Image.h
Program Description:
This Class defines and image object header
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

class Image{
	private:
		int NumRows;
		int NumCols;
		int DataLength;
		float *Data;
	public:
		Image(int, int);
		Image(const Image &OriginalImage);
		~Image();
		int getNumRows(void);
		int getNumCols(void);
		float GetVal(int, int);
		void SetVal(int, int, float);
		void PrintImage();
		void ReadImage(char*);
		void WriteImage(char*);
		bool CheckIndex(int, int);
		
};