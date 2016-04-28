/*
Name: Quit_Window
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to create a window that asks whether a user really wants to quit or not.
If the user clicks the no button they are returned to the previous window and if they click
yes the game is closed down.
*/

#ifndef Quit_Window_H
#define Quit_Window_H
#include "Question_Window.h"

class Quit_Window: public Question_Window{
	
		private:
   
   				static void no_cb(Fl_Widget* w, void* v);
   
   		public:
   
   				static void yes_cb(Fl_Widget* w, void* v);
   				Quit_Window(int width, int height);
				virtual ~Quit_Window() {};
};

#endif

