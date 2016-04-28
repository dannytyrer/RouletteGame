/*
Name: Quit_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the functions of the Quit_Window class.
*/

#include "Quit_Window.h"
#include "Game_Window.h"

/*
Callback function for the yes button, this exits the program.

Returns: Nothing.
*/

void Quit_Window::yes_cb(Fl_Widget* w, void* v){

   		exit(0);
}

/* 
Callback function for the no button, this returns the program to the previous 
window.

Returns: Nothing.
*/

void Quit_Window::no_cb(Fl_Widget* w, void* v){
   
   		((Quit_Window*)v)->hide();
}


/*
Constructor for the quit window.

Returns: Nothing.
*/
Quit_Window::Quit_Window(int width, int height) :Question_Window(width, height, "Exit", 
                                                                                     "Are you sure you want to quit? You could hit the jackpot!!"){   
   		((Fl_Button*) yes)->callback(yes_cb);
   		((Fl_Button*) yes)->shortcut(FL_Enter);
   		((Fl_Button*) no)->callback(no_cb,this);
   		show();  
}




