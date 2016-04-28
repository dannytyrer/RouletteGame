/*
Name: Bet_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to format the part of the game window where users can input bet details. This is defined as a class
so that if an alternate design is produced, it can be replaced by a small amount of code in the Game_Window class.
It makes use of the classes Innerbet_Window and Outerbet_Window for the designs of the parts of the window which correspond
to the inner bet and outer bet types respectively.

Parameter inner: An array which stores all 37 different types of innerbet design, is defined as an Fl_Group* for the allowance of
                 other designs to be inserted easily.
Parameter outer: An array which stores all 9 types of outerbet design.This is defined as an Fl_Group* for the allowance of
                 other designs to be inserted easily.	  	  	    
*/

#ifndef Bet_Window_H
#define Bet_Window_h
#include "Inside_Window.h"

class Bet_Window:public Inside_Window{
    
		private:
		
      			Fl_Group* inner[37];
      			Fl_Group* outer[9];
				void generate_inner(int w, int h);
				void generate_outer(int w, int h);
    	public:
	   
	   			Bet_Window(int x, int y, int w, int h);
				virtual ~Bet_Window() { delete[] inner; delete[] outer; };
       			Fl_Group** get_inner_bets();	
       			Fl_Group** get_outer_bets();
};

#endif

