#Jay Battle
#BIEN 4290 -
#March 28, 2017
#Lab 4
#Makefile
#this is a Makefile for creating a runMaxMaskFilter executable
	
runMaxMaskFilter.o: runMaxMaskFilter.cpp Image.cpp Filter.cpp LocalMaxMaskFilter.cpp Image.h Filter.h LocalMaxMaskFilter.h
	g++ -o runMaxMaskFilter runMaxMaskFilter.cpp Image.cpp Filter.cpp LocalMaxMaskFilter.cpp -lm