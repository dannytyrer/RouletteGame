/*
Name: Startup_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Startup_Window class.
*/

#include "Startup_Window.h"
#include "Quit_Window.h"
#include "Game_Window.h"
#include "JPEG_Image_Box.h"
#include "Notification_Window.h"
#include "Useful_Functions.h"
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include <iostream>

/*
Definitions for use in the animation of the wheel.

Parameter TOTAL: The total number of casino images.
Parameter RATE: The rate at which the images are shown.
Parameter jpgs: An array to hold the images when they have been stored in memory.
Parameter casinb: The box where the animation is to take place is redrawn every time
              	  a different image is put up.
*/

#define TOTAL 13
#define RATE 0.5
Fl_JPEG_Image* jpgs1[13];
JPEG_Image_Box* casinb;

/*
This function displays the next image on the screen each time it is enterred.
Code is adapted from that displayed on "http://seriss.com/people/erco/fltk/"
under the header animation example.

Returns: Nothing.
*/

void Startup_Window::show_next_cb(void* v){
   
   		static int x=0;
   		casinb->image(jpgs1[x++ % TOTAL]);
   		casinb->redraw();
   		Fl::repeat_timeout(RATE, show_next_cb); 
}

/*
Loads the images needed for the wheel spinning animation. Code is adapted from that
displayed on "http://seriss.com/people/erco/fltk/" under the header animation example.

Returns: 1 if the file does not load correctly, 0 if it does. 
*/

int Startup_Window::load_casino(int noim){

   		for(int t=0;t<noim;t++){
	     
		 		char filename1[80];
	     		sprintf_s(filename1, "cas%d.jpg",t+2);
	     		jpgs1[t]= new Fl_JPEG_Image(filename1);
		 		if(jpgs1[t]->w()==0){
 
						perror(filename1);
						return 1;
	     		}
    	}
		
		return 0;
}

/*
Accessor method for the Fl_Input* holding the name of the player.

Returns: The field, name.
*/

Fl_Input* Startup_Window::get_name(){

   		return name;
}

/*
Callback for the quit button, opens a new Quit_Window.

Returns: Nothing.
*/

void Startup_Window::quit_cb(Fl_Widget* w, void* v){
   
    	Quit_Window* quit= new Quit_Window(500, 200);      
}

/*
Callback for the enter button. If the input name is correct then a new game window is opened,
if it is not then an error message is displayed.

Returns: Nothing.
*/
   
void Startup_Window::enter_cb(Fl_Widget* w, void* v){
        static const int min_name_size=4;
   		std::string s=const_char_to_string((((Startup_Window*) v)->get_name())->value());
		int counter=std::count(s.begin(),s.end(),' ');
   		if(s.size()<min_name_size||counter>0){
  
   				Notification_Window* error=new Notification_Window(500,200,"Error","Is that a fake ID?!\n (Name must be longer than 4 characters and not contain spaces)",0);
   		}else{
   
   				
   				Fl_Group* g=new Game_Window(0,0,1360,700,"Roulette", s);
				((Startup_Window*) v)->hide(); 
   		}
}    

/*
This function formats the button with a white bold label and a black
background.

Returns: Nothing.
*/

Fl_Button* Startup_Window::button_format(Fl_Button* b){

   		b->color(FL_BLACK);
   		b->labelcolor(FL_WHITE);
   		b->labelfont(FL_BOLD);
   		return b;
}


/*
Constructor for the Startup_Window window
This loads the images required for the animation into memory. It intialises all buttons
to implement the design of the window.

Returns: Nothing.
*/

Startup_Window::Startup_Window(int x, int y, int width, int height, const char *title): Fl_Window(x, y, width, height, title) {
   
   		load_casino(13);
   		casinb=new JPEG_Image_Box(0,0,500,250,"Cas14.jpg");
   		JPEG_Image_Box* tablebox=new JPEG_Image_Box(0,250,500,250,"table.jpg");
   		name=new Fl_Input(200, 350, 100, 30);   
   		Fl_Button*  enterbutton=new Fl_Button(100, 400, 300, 30, "Get me in there");
   		enterbutton=button_format(enterbutton);
   		enterbutton->callback(enter_cb, this);
   		enterbutton->shortcut(FL_Enter);  
   		Fl_Button*  quitbutton=new Fl_Button(100, 450, 300, 30, "I'm sorry but gambling isn't for me");
   		quitbutton=button_format(quitbutton);
   		quitbutton->callback(quit_cb,this);
   		show();
   		Fl::add_timeout(RATE, show_next_cb);   
}


