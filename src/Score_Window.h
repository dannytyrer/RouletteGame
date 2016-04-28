/*
Name: Score_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class implements the design for displaying the games state on the user interface.

Parameter: all parameters are of the type Fl_Text_Display* and displays the information about
           the game that their name states.
*/

#ifndef Score_Window_H
#define Score_Window_h
#include "Player.h"
#include "Inside_Window.h"
#include <FL/Fl_Text_Display.H>

class Score_Window:public Inside_Window{

		private:
   
   				Fl_Text_Display* name_display;
   				Fl_Text_Display* level_display;
   				Fl_Text_Display* score_display;
   				Fl_Text_Display* amount_display;
   				Fl_Text_Display* target_display;

   		public:
    		
				Score_Window(int x, int y, int w, int h, Player p1);
				virtual ~Score_Window() { delete name_display; delete level_display; delete score_display; delete amount_display; delete target_display; };
				void update(Player pin);
    			void format_name_display(std::string name, int w, int h);
				void format_level_display(int level, int w, int h, bool first);
    			void format_score_display(int score, int w, int h, bool first);
				void format_amount_display(int amount,int w, int h, bool first);
				void format_target_display(int target, int w, int h, bool first);
				Fl_Text_Display* get_name_display();
				Fl_Text_Display* get_level_display();
				Fl_Text_Display* get_score_display();
				Fl_Text_Display* get_amount_display();
				Fl_Text_Display* get_target_display();
};
   
#endif   

