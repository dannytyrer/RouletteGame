/*
Name: Notification_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to display a message in a pop up window. Any pop up window which
displays a message inherits from this class. This class makes use of the Message_Box
class to display the message.

Parameter: mess stores the Message_Box that contains the message to the user.
	       this is stored as protected to allow access for children of this class.  
*/

#ifndef Notification_Window_H
#define Notification_Window_H
#include "Outside_Window.h"
#include "Message_Box.h"

class Notification_Window:public Outside_Window{
        
		protected:
		        Message_Box* mess;
		
        public:
		        Notification_Window(int x, int y, int width, int height, const char* title,const char* message);
				Notification_Window(int width, int height, const char* title, const char* message, int test);
				virtual ~Notification_Window() { delete mess; }
};

#endif

