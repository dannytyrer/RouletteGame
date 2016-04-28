/*
Name: Notification_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the class Notification_Window.
*/

#include "Notification_Window.h"

/*
Constructor for the Notification_Window

Parameter test: if test is 0 then a notifcation window object is explicitly shown() if not then it isn't.

Returns: Nothing.
*/

Notification_Window::Notification_Window(int width, int height, const char* title, const char* message, int test):Outside_Window(width, height, title){

        mess= new Message_Box(0,0,width,height,message);
		if(test==0){
		
				show();
		}
}


