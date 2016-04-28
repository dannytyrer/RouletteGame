/*
Name: Game_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class constructs the main window for the roulette game. The window is updated when bets have been made to
display the current state of the users progress in the game. This class makes use of a player object
to store information about the player. The Bet_Window class and Score_Window class to construct the game
and to display the information about the player respectively. The roulette_Menu class is used to create a menu
for display on this window.

Parameter current_player: Stores the player object for the current game run. The player object is changed to
                          match the current state of the game.
Parameter win_display: A text field which is ued to show the result of the last bet which was made, displaying
					   the winning number, whether the bet was won or lost, and how much the player won or lost.
Parameter score_display: Stores the part of the window where the current state of the game is displayed to the user. This is 
                         defined as an Fl_Group* to allow for different designs to be created for this part of the
					     window and for them to be inserted easily.
Parameter bet_display: Stores the part of the window where the user inputs bet information. This is 
                       defined as an Fl_Group* to allow for different designs to be created for this part of the
					   window and for them to be inserted easily.
Parameter over: Holds the Endgame_Window so that the window can be closed from within the player class.
Parameter place_button: Holds the place bet button, this is so that the button can be re-activated from within 
					    the run_animation_cb function.	  	  	  	  	  	     
*/

#ifndef Game_Window_H
#define Game_Window_H
#include "Player.h"
#include "Inside_Window.h"
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

class Game_Window: public Inside_Window{
   
   		private:
   				Player current_player;
   				Fl_Text_Display* win_display;
   				Fl_Group* score_display;
   				Fl_Group* bet_display;
				void* over;
				Fl_Widget* place_button;
   				static void run_animation_cb(void* v);
   				int load_wheel(int noim);
   				void set_winner(int win, int w, int h, int first, int lucky);   
   				static void place_bet_cb(Fl_Widget* w, void* v);
   				static void quit_cb(Fl_Widget* w, void* v);
   				
   
   		public:
                
   				Fl_Button* get_place_button();
   				void set_over(void* overin);
   				void* get_over();
   				void restart_game();
   				Fl_Text_Display* get_winner();
   				Fl_Group* get_bet();
				Fl_Group* get_score();
				void set_score(Fl_Group* scorein);
				Player get_player();
				void set_player(Player pin);
				Game_Window(int x, int y, int w, int h, const char *title, std::string s);
				virtual ~Game_Window() { delete win_display; delete score_display; delete bet_display; delete over; delete place_button; };
};

#endif

