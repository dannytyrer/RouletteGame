/*
Name: Inside_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class creates a green window. All windows show inside the game that are not pop up windows inherit from it.
This is to avoid code duplication when all children windows display the same properties as it.
*/

#ifndef Inside_Window_H
#define Inside_Window_H
#include <FL/Fl_Window.H>

class Inside_Window: public Fl_Window{
		
        public:
   
                Inside_Window(int x, int y, int width, int height, const char* title);
	            Inside_Window(int width, int height, const char* title);
				virtual ~Inside_Window() {};
};

#endif

