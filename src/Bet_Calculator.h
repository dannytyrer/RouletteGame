/*
Name: Bet_Calculator.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class creates a window which can be used to calculate the total bet amount and the return that
the user would get from this bet if it won.

Parameter input: An array which stores the Int_Input fields where the used enters information.
Parameter output: An array which stores the Fl_Text_Displays where the result from the users input is shown.
*/


#ifndef Bet_Calculator_H
#define Bet_Calculator_H
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Text_Display.H>
#include "Inside_Window.h"

class Bet_Calculator : public Inside_Window{
    
		private:
	
				Fl_Int_Input* input[11]; 
				Fl_Text_Display* output[2];
				static void input_cb(Fl_Widget* w, void* v);
    
		public:
	
				Bet_Calculator(int x, int y, int w, int h, const char* title);
    			Fl_Int_Input** get_input();
    			Fl_Text_Display** get_output();
				virtual ~Bet_Calculator() { delete[] input; delete[] output; };
};

#endif

