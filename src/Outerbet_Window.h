/*
Name: Outerbet_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class implements the design of the outer bet fields where the user inputs information.

Parameter field: The Fl_Int_Input where the user enters bet values.
*/

#ifndef Outerbet_Window_H
#define Outerbet_Window_H
#include <FL/Fl_Int_Input.H>
#include "Inside_Window.h"

class Outerbet_Window:public Inside_Window{
		
		private:   
      
	  			Fl_Int_Input* field;

   		public:
      
	  			Fl_Int_Input* get_field();
      			Outerbet_Window(int x, int y , int w, int h, int k);
				virtual ~Outerbet_Window() { delete field; };

};

#endif 

