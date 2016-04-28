/*
Name: JPEG_Image_Box
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to create a box with a JPEG image displayed on it. It is to avoid
code duplication, as a JPEG image is needed to be shown in multiple locations. It is 
similar to the Message_Box class in this regard.
*/

#ifndef JPEG_Image_Box_H
#define JPEG_Image_Box_H
#include <FL/Fl_Box.H>

class JPEG_Image_Box: public Fl_Box{

        public:
		        JPEG_Image_Box(int x, int y, int width, int height, const char* filename);
				virtual ~JPEG_Image_Box() {};
};

#endif

