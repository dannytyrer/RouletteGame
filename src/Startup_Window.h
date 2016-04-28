/*
Name: Startup_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class displays the startup window for the game, which prompts the user to enter
their name to start the game.

Parameter name: The Fl_Input* where the user is to enter their name.
*/

#ifndef Startup_Window_H
#define Startup_Window_H
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "JPEG_Image_Box.h"
class Startup_Window : public Fl_Window{

		private:
		
     			Fl_Input* name;  
	 			Fl_Button* button_format(Fl_Button* b);
	 			static void show_next_cb(void* v);	 	 	 
     			static void  quit_cb(Fl_Widget* w, void * v);
	 			static void  enter_cb(Fl_Widget* w, void* v);
     			static void  text_cb(Fl_Widget* w, void* v);
     			int load_casino(int noim);
    
   		public:
      
	  			Fl_Input* get_name();
	  			Startup_Window();
      			Startup_Window(int x, int y, int width, int height, const char *title);
				~Startup_Window() { delete name; };
};

#endif

