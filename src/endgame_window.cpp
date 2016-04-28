/*
Name: Endgame_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Endgame_Window class.
*/

#include "Endgame_Window.h"
#include "Quit_Window.h"
#include "Game_Window.h"

/*
This is the callback function for the restart button. It calls the restart_game() method
of the Game_Window and then hides the Endgame_Window. 

Returns: Nothing.
*/

void Endgame_Window::restart_cb(Fl_Widget* w, void* v){

		((Game_Window*)v)->restart_game();
   		((Endgame_Window*)(((Game_Window*) v)->get_over()))->hide();
}

/*
This is the contructor for the Endgame_Window.

Returns: Nothing.
*/

Endgame_Window::Endgame_Window(int width, int height, const char* title, const char* message, void* current): Question_Window(width, height, title, message){
    
    	((Fl_Button*) yes)->callback(restart_cb, current);
		((Fl_Button*) no)->callback(Quit_Window::yes_cb);
		((Fl_Button*) yes)->show();
		((Fl_Button*) no)->show();
		show();
}



