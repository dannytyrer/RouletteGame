/*
Name: Outerbet_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the class Outerbet_Window.
*/

#include "Outerbet_Window.h"
#include "Message_Box.h"

/*
Accessor function for the Fl_Int_Input field.

Returns: The field field.
*/

Fl_Int_Input* Outerbet_Window::get_field(){
   
   		return field;
}

/*
Constructor for the Outerbet_Window.

Parameter k: a variable to test what type of bet the current Outerbet_Window is.
         If k is less than 3 then the Int_Input and Message_Box are drawn larger
		 to match the design of the window.
Parameter type: The type of bet of the current Outerbet_Window.

Returns: Nothing.
*/

Outerbet_Window::Outerbet_Window(int x, int y, int width, int height, int k): Inside_Window(x,y,width,height,""){
 
   		begin();
   		Message_Box* name;
   		const char* type="";
   		switch(k){
      			case 9: type="19 to 36"; break;
      			case 8: type="Odd"; break;
      			case 7: type="Red"; break;
      			case 6: type="Black"; break;
      			case 5: type="Even"; break;
      			case 4: type="1 to 18"; break;
      			case 3: type="3rd 12"; break;
      			case 2: type="2nd 12"; break;
      			case 1: type="1st 12"; break;
   		}     
   
   		if(k<=3){
    			field= new  Fl_Int_Input(0,3*height/4,width,height/4,"");
				name= new Message_Box(0,0,width,3*height/4,"");
   		}else{
      			field=new Fl_Int_Input(0,height/2,width,height/2,"");
      			name= new Message_Box(0,0,width,height/2,"");
   		}
    	name->label(type);
		name->box(FL_BORDER_FRAME);     
   		name->redraw();
   		end();  
}

