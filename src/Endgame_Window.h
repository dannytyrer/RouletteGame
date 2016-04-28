/*
Name: Endgame_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used when a player's balance has fallen to 0.It opens a window which informs
the player if their score has made the high score list or not and then prompts the user as
to whether they want to play again. 
*/

#ifndef EndGame_Window_Window_H
#define EndGame_Window_Window_H
#include "Question_Window.h"

class Endgame_Window: public Question_Window{

		private:
          		static void restart_cb(Fl_Widget* w, void* v);
   
   		public:
          		Endgame_Window(int width, int height, const char* title, const char* message, void* current);
				virtual ~Endgame_Window() {};
};

#endif

