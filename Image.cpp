/*
Jay Battle
BIEN 4290 -
March 28, 2017
Lab 4
Image.cpp
Program Description:
This Class defines and image object
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<iostream>
#include <fstream>
using namespace std;
#include "Image.h"


	Image::Image(int rows, int columns){
		Data = NULL;
		NumRows = rows;
		NumCols = columns;
		DataLength = (NumRows*NumCols);
		Data = new float[NumRows*NumCols]; 	
	}
	
	Image::Image(const Image &originalImage){ 		
		NumRows = originalImage.NumRows;
		NumCols = originalImage.NumCols;
		DataLength = originalImage.DataLength;
		Data = new float[NumRows*NumCols];
		for (int currRow=0; currRow<originalImage.NumRows; currRow++) {
			for (int currCol=0; currCol<originalImage.NumCols; currCol++) {
				Data[(currRow*NumCols)+currCol] = originalImage.Data[(currRow*NumCols)+currCol];
			}
		}
	}
	
	Image::~Image() {
		if (Data != NULL) { 
			delete []Data;
			Data = NULL;
		}
	}
	
	int Image::getNumRows(void) {return NumRows;}
	
	int Image::getNumCols(void) {return NumCols;}
	
	float Image::GetVal(int row, int column){
		int index = (row*NumCols)+column;
		if (CheckIndex(row, column)) return Data[index];
		else return -1;
	}
	
	void Image::SetVal(int row, int column, float newVal){ 
		int index = ((row*NumCols)+column);
		if (CheckIndex(row, column)) Data[index] = newVal;
	}
	
	void Image::PrintImage(void) {
		for (int currRow=0; currRow<NumRows; currRow++) {
			for (int currCol=0; currCol<NumCols; currCol++) 
				cout<<"Pixel: ("<<currRow<<","<<currCol<<") = "<<GetVal(currRow,currCol)<< "\n";
		}
	}
	
	void Image::ReadImage(char* filename){
		float val=0;
		std::ifstream infile;
		infile.open(filename, std::ios::in|std::ios::binary);
		if (infile.is_open()){
			infile.read((char*)Data, NumRows*NumCols*4);
			infile.close();
		} else {
			std::cout<<"Unable to open "<<filename<<" for reading \n";
			exit(0);
		}
	}
	
	void Image::WriteImage(char* filename){
		float val=0;
		std::ofstream outfile;
		outfile.open(filename, std::ios::out|std::ios::binary);		
		if (outfile.is_open()){
			outfile.write((char*)Data, NumRows*NumCols*4);
			outfile.close();
		} else {
			std::cout<<"Unable to write to "<<filename<<"\n";
			exit(0);
		}
	}

	bool Image::CheckIndex(int row, int column){
		if (row>NumRows || row<0){
			cout<<"Invalid Row\n";
			return false;
		}
		if (column>NumCols || column<0){
			cout<<"Invalid Col\n";
			return false;
		}
		return true;
	}
	
	
	
	


