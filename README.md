# LocalMaxMaskFilter
An OOP approach to image filtering using a Local Mask Max Filter implemented in C++

Author: Jay Battle
Course: BIEN 4290
Refrences: My alma mater
Languages: C++, Bash, Command Line
Platform: UNIX
Purpose: Sample C++ Project
Status: In revisions

Description:
This class inspired project creates a automated command line interface to accomplish image
filtering on a image file creating an new copy of the filtered image. A local Max Mask Filter
was implemented in this example project. This project consists of C++ programs, and a Makefile.
A sample image is included for testing. The output of the project is a filtered image file.
The images are in floting point binary format (4 bytes). Use matlab to view the images.

Instructions:
To run runMaxMaskFilter.cpp enter the following commands
Step 1: make
Step 2: ./runMaxMaskFilter.cpp {Image Lenght} {Image Width} {Image Filename} {Output Filename} {Filter Lenght} {Filter Width}
