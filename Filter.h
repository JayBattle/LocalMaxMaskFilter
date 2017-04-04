/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
Filter.h
Program Description:
This Class defines and Filter object header
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Image.h"

class Filter{
	protected:
		virtual float UpdatePixel(Image&, int, int);
		
	public:
		Image Process(Image&, int, int);
};
