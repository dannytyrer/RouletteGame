/*
Name: Messgae_Box.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Message_Box class.
*/

#include "Message_Box.h"

/*
Constructor for a Message_Box with the message displayed in the centre of the box
with a white and bold font.

Parameter message: The message to be displayed in the box.

Returns: Nothing.
*/

Message_Box::Message_Box(int x, int y, int width, int height, const char* message):Fl_Box(x,y,width,height,message){

        this->align(FL_ALIGN_CENTER);
        this->labelcolor(FL_WHITE);
        this->labelfont(FL_BOLD);
        show();
}

