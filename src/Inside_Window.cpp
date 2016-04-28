/*
Name: Inside_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Inside_Window class.
*/

#include "Inside_Window.h"

/*
Constructor for an Inside_Window with no x,y point defined.

Returns: Nothing.
*/


Inside_Window::Inside_Window(int width, int height, const char* title):Fl_Window(width, height, title){

        Fl_Color c=fl_rgb_color(0,153,0);
		this->color(c);
}

/*
Constructor for an Inside_Window with an x and y co-ordinate specified.

Returns: Nothing.
*/

Inside_Window::Inside_Window(int x, int y, int width, int height, const char* title):Fl_Window(x, y, width, height, title){

        Fl_Color c= fl_rgb_color(0,153,0);
		this->color(c);
}


