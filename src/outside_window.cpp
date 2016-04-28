/*
Name: Outside_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the class Outside_Window.
*/

#include "Outside_Window.h"

/*
Constructor for the outside window in a position defined by x and y.

Returns: Nothing.
*/

Outside_Window::Outside_Window(int x, int y, int width, int height, const char* title):Fl_Window(x,y, width, height, title){

   this->color(FL_BLACK);
}

/*
Constructor for the Outside_Window with no defined x and y.

Returns: Nothing.
*/

Outside_Window::Outside_Window(int width, int height, const char* title):Fl_Window(width, height, title){

   this->color(FL_BLACK);
}

