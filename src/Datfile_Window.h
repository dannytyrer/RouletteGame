/*
Name: Datfile_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class creates a window which displays a file of .dat type. 
*/

#ifndef Datfile_Window_H
#define Datfile_Window_H
#include "Inside_Window.h"
#include "Datfile_Window.h"
#include <iostream>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

class Datfile_Window: public Inside_Window{ 
    private:
	Fl_Text_Buffer* buff;
	Fl_Text_Display* disp;
    public:
	        
			Datfile_Window(int x, int y, int width, int height, const char* title, const char* filename, const char* message);
			virtual ~Datfile_Window() { delete buff; delete disp; };

};

#endif

