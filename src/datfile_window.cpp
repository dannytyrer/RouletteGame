/*
Name: Datfile_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Datfile_Window class.
*/

#include "Datfile_Window.h"
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>


/*
Constructor for the Datfile_Window class.

Returns: Nothing.
*/

Datfile_Window::Datfile_Window(int x, int y, int width, int height, const char* title, const char* filename, const char* message):Inside_Window(x,y,width, height, title){

		buff= new Fl_Text_Buffer;
		disp= new Fl_Text_Display((width*0.1)/2,(height*0.1)/2,width*0.9,height*0.9);
		disp->buffer(buff);
    	buff->append(message);
		buff->appendfile(filename);
		show();
}


