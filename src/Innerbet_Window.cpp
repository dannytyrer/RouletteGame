/*
Name: Innerbet_Window.cpp
Author Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Innerbet_Window class.
*/

#include "Innerbet_Window.h"
#include "Message_Box.h"
#include <iostream>

/*
Accessor method for the Fl_Int_Input* field.

Returns: The field field.
*/

Fl_Int_Input* Innerbet_Window::get_field(){
   
   		return field;
}

/*
Constructor for the Innerbet_Window class. 

Parameter red: true if the current number corresponds to a red number, false otherwise.
Parameter nn: the label string for the number box.

Returns: Nothing.
*/


Innerbet_Window::Innerbet_Window(int x, int y, int width, int height, const char* nn, bool red):Inside_Window(x,y,width,height,""){
   		
		begin();
      	numb= new Fl_Box(0,0,width/2,height); 
      	numb->box(FL_OVAL_BOX);
		numb->label(FL_NORMAL_LABEL, nn);
      	numb->labelcolor(FL_WHITE);
      	numb->labelfont(FL_BOLD);
	    if(red){
        		numb->color(FL_RED);
     	}else{
        		numb->color(FL_BLACK);
     	}
  		field= new Fl_Int_Input(width/2, 0, width/2, height);
  		numb->redraw();
  		end();
}

/*
Constructor for the case when the number is 0.

Returns: Nothing.
*/

Innerbet_Window::Innerbet_Window(int x, int y, int width, int height):Inside_Window(x,y,width,height,""){

		begin();
   		numb=new Message_Box(0,0,width/2,height,"0");
		field= new Fl_Int_Input(width/2, 0, width/2, height);
  		numb->redraw();
  		end();
}

