/*
Name: Bet_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Bet_Window class.
*/

#include "Bet_Window.h"
#include "Outerbet_Window.h"
#include "Innerbet_Window.h"
#include "Useful_Functions.h"
#include <iostream>
#include <windows.h>
/*
Accessor method for the inner field.

Returns: Pointer to array that contains all Innerbet_Windows.
*/

Fl_Group** Bet_Window::get_inner_bets(){

		return inner;
}

/*
Accessor method for the outer field.

Returns: Pointer to array that contains all Outerbet_Windows.
*/

Fl_Group** Bet_Window::get_outer_bets(){

	    return outer;
}

/*
Sets the positions of all the innerbet_Windows in the Bet_Window.
In a function so other designs could be inserted easily.

Parameter numbers: An array holding the labels for each number.

Returns: Nothing
*/

void Bet_Window::generate_inner(int width, int height){

   		Fl_Group* newbox1=new Innerbet_Window(2*width/3,0,width/6,(height/14));
   		inner[0]=newbox1;
   		int j=1;
		static const char* const number_labels[] = {"1", "2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18",
		                                     "19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34",
											 "35","36"};
   		for(int i=1;i<35;i+=3, j++){
		        
	  			  inner[i]=new Innerbet_Window(width/2,((j)*height/13),width/6,(height)/14,number_labels[i-1],is_red(i));
      			  inner[i+1]=new Innerbet_Window(2*width/3,((j)*height/13),width/6,(height)/14,number_labels[i],is_red(i+1));
      			  inner[i+2]=new Innerbet_Window(5*width/6,((j)*height/13),width/6,(height)/14,number_labels[i+1],is_red(i+2));  	            
   		}
}

/*
Sets the positions of all the outerbet_Windows in the Bet_Window.
In a function so other designs could be inserted easily. This function uses 
four counters to initialise the Outerbet_Windows and save them to the outer array.

Returns: Nothing
*/

void Bet_Window::generate_outer(int width, int height){
  
		int j=1;
   		int k=0;
   		int l=0;  
   		for(int i=0;i<height;i+=height/6, j++, k+=height/3,l++){
   
      			Fl_Group* newbox= new Outerbet_Window(0,i,width/4,height/6,j+3);
	  			outer[l]=newbox;
	  			if(l<3){
				
      					Fl_Group* newbox2=new Outerbet_Window(width/4,k,width/4,height/3,j);
      					outer[l+6]=newbox2;
	  			}
         }  
}

/*
Constructor for the Bet_Window.

Returns: Nothing.
*/

Bet_Window::Bet_Window(int x, int y, int width, int height):Inside_Window(x,y,width,height,""){

		begin();
   		generate_outer(width,height); 
   		generate_inner(width,height);
   		end();
}



