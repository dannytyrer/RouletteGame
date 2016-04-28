/*
Name: Roulette_Menu.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to create the menu for the roulette game. It contains buttons to; open the instructions,
open the high scores, open the bet calculator, restart the game and to quit the game.
*/

#ifndef Roulette_Menu_H
#define Roulette_Menu_H
#include <FL/Fl_Menu_Button.H>

class Roulette_Menu : public Fl_Menu_Button{
   
   		private:
   			
				static void inst_cb(Fl_Widget* w, void* v);
   				static void high_cb(Fl_Widget* w, void* v);
   				static void calc_cb(Fl_Widget* w, void* v); 
   				static void quit_cb(Fl_Widget* w, void* v);
   				static void restart_cb(Fl_Widget* w, void* v);
   		
		public:
        
  				Roulette_Menu(int x, int y, int w, int h, const char *title);
				virtual ~Roulette_Menu() {};
};

#endif

