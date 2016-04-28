/*
Name: Question_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

Ths class is to display a pop up window that asks the user a yes or no question.
Any window that asks the user a question inherits from this class.

Parameter yes: Stores the yes button of the window. Stored as an Fl_Widget* as an Fl_Button* does not
		       have a constructor that has no arguments.
Parameter no: Stores the no button of the window. Stored as an Fl_Widget* as an Fl_Button* does not
		      have a constructor that has no arguments.
*/

#ifndef Question_Window_H
#define Question_Window_H
#include "Notification_Window.h"
#include <FL/Fl_Button.h>

class Question_Window: public Notification_Window{

   		protected:
   
      			Fl_Widget* yes;
	  			Fl_Widget* no;
   
   		public:
   
    			Question_Window(int width, int height, const char *title, const char* message);
				virtual ~Question_Window() { delete yes; delete no; }
};

#endif

