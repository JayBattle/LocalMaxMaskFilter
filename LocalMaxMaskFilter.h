/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
LocalmaxMaskFilter.h
Program Description:
This Class defines a Local Max Mask Filter object header
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Filter.h"

class LocalMaxMaskFilter : public Filter {
	protected:
		virtual float UpdatePixel(Image&, int, int);
};