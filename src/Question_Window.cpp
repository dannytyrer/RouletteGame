/*
Name: Question_Window
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the functions of the class Question_Window.
*/

#include "Question_Window.h"

/*
Constructor for the Question_Window.
The Message_Box inherited from Notification_Window is resized
to account for the two added Fl_Buttons.

Returns: Nothing.
*/

Question_Window::Question_Window(int width, int height, const char* title, const char* message): Notification_Window(width, height, title, message,1){
   		
		this->set_modal();
  	    mess->size(width,height/4);
  		mess->position(0,height/4);
   		yes=new Fl_Button(width/5,(3*height/4),(4*width/25),height/5, "Yes");
   		no=new Fl_Button((16*width/25) ,(3*height/4) ,(4*width/25),height/5,"No"); 
}


