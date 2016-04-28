/*
Name: Roulette_Menu.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Roulette_Menu class.
*/

#include "Roulette_Menu.h"
#include "Quit_Window.h"
#include "Bet_Calculator.h"
#include "Game_Window.h"
#include "Datfile_Window.h"

/*
Callback function for the instructions button, opens a Datfile_Window containing the instructions.

Returns: Nothing.
*/

void Roulette_Menu::inst_cb(Fl_Widget* w, void *v){

   		Datfile_Window* instr= new Datfile_Window(0,0,600,650,"Instructions","instructions.dat","");
}

/*
Callback function for the high scores button. Opens a Datfile_Window containing the high scores.]

Returns: Nothing.
*/

void Roulette_Menu::high_cb(Fl_Widget* w, void *v){

   		Datfile_Window* highs= new Datfile_Window(0,0,250,325, "High Scores","highscore.dat","High Scores\n\n");
}

/*
Callback function for the bet calculator button. Opens a Bet_Calculator.

Returns: Nothing.
*/

void Roulette_Menu::calc_cb(Fl_Widget* w, void *v){

   		Bet_Calculator* betc=new Bet_Calculator(0,0,600,600,"Bet Calculator");
}

/*
Callback function for the restart button. Calls the restart_game function from Game_Window
and opens a Notification_Window notifying the user of the restarting.

Returns: Nothing.
*/

void Roulette_Menu::restart_cb(Fl_Widget* w, void* v){

   		((Game_Window*)(((Roulette_Menu*) v)->parent()))->restart_game();
   		Notification_Window* ree=new Notification_Window(500,200,"Restart","The game has been reset",0 );
   		ree->show();
}
/*
Callback for the quit button, opens up a Quit_Window.

Returns: Nothing.
*/

void Roulette_Menu::quit_cb(Fl_Widget* w, void *v){
   
   		Quit_Window* quit= new Quit_Window(500, 200);
}

/*
Constructor for the ROulette_Menu. Adds a button for each feature of the game and assigns a shortcut 
to each button.

Returns: Nothing.
*/

Roulette_Menu::Roulette_Menu(int x, int y, int w, int h, const char* title):Fl_Menu_Button(x,y,w,h,title){

   		this->add("Instructions", FL_CTRL+'i', inst_cb);
   		this->add("High Scores", FL_CTRL+'h', high_cb);
   		this->add("Bet Calculator", FL_CTRL+'c', calc_cb);
   		this->add("Restart", FL_CTRL+'r', restart_cb, this);
   		this->add("Quit", FL_CTRL+'q', quit_cb);   
   		show();
}

