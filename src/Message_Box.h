/*
Name: Message_Box.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to create a box with a message displayed on it as it's label. The label
is formatted to be bold, white and aligned in the centre of the window in which it is displayed.
This is used to avoid code duplication in a similar way to the JPEG_Image_Box class.
*/

#ifndef Message_Box_H
#define Message_Box_H
#include <FL/Fl_Box.H>

class Message_Box: public Fl_Box{

   		public:
   
      			Message_Box(int width, int height, const char* message);   
      			Message_Box(int x, int y, int width, int height, const char* message);
				virtual ~Message_Box() {};
};

#endif

