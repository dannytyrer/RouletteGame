/*
Name: JPEG_Image_Box.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the JPEG_Image_Box class.
*/

#include "JPEG_Image_Box.h"
#include <FL/Fl_JPEG_Image.H>
#include <string>
#include <iostream>
/*
Constructor for a JPEG_Image_Box

Parameter filename: The name of the JPEG image file to be shown.

Returns: Nothing.
*/

JPEG_Image_Box::JPEG_Image_Box(int x, int y, int width, int height, const char* filename):Fl_Box(x,y,width,height){

		Fl_JPEG_Image* imag= new Fl_JPEG_Image(filename);
        this->image(imag);
        show();
}

