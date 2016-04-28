/*
Name: Innerbet_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class implements the design of the inner bet fields where the user inputs information.

Parameter numb: The box which holds the number and design that describes the bet.
Parameter field: The Fl_Int_Input* where bet values are entered by the user.
*/

#ifndef Innerbet_Window_H
#define Innerbet_Window_H
#include <FL/Fl_Int_Input.H>
#include "Inside_Window.h"
#include <Fl/Fl_Box.h>

class Innerbet_Window:public Inside_Window{

		private:
		
				Fl_Box* numb;
        		Fl_Int_Input* field;
   
   		public:
   				
				void set_label(const char* lab);
      			Fl_Int_Input* get_field();
      			Innerbet_Window(int x, int y, int w, int h, const char* nn, bool red);
				Innerbet_Window(int x, int y, int w, int h);
				virtual ~Innerbet_Window() {delete numb; delete field;};
};

#endif

