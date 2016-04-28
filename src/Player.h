/*
Name Player.h
Author Daniel Tyrer
Last Edited: 21/01/2015

This class is used to store the state of the game of roulette. When the game is started a new
player object is created which is then altered so that its members match the state of the current
roulette game. This is kept seperate from the gui implementation in order to achieve model-view
seperation.

Parameter name: String used to store the name of the current player of the game.
Parameter amount: int used to store the current balance of the player.
Parameter level: int used to store the level which the player is at.
Parameter goal: int used to store the value needed to be achieved to reach the next level.
Parameter score: int used to store the players score.
Parameter number: int used to store the number last landed on by the spin of the roulette wheel.
Parameter before_amount: int used to store the amount a player has after a bet has been placed
                         but before the result has come through. Is used in checking whether a user
	    				 has exceeded their balance or not.
Parameter result: int used to store the result of the last wheel spin. The sign of this says whether
                  the bet has been won or lost (+ win, - loss) and the magnitude of this number is
			      the amount the player has either won or lost.
Parameter error:  bool which is changed to true if something is wrong with the information the player
                  has input which is checked to throw up an error message.
*/


#ifndef Player_H
#define Player_H
#include <string>
#include <FL/Fl_Group.H>

class Player {

			private:
	        		
		   			bool error;
					std::string name;
					int amount;
					int level;
					int goal;
					int score;
					int number;
					int before_amount;
					int result;
					void check_level();	
						
			public:
       
	   				Player();
					~Player() {};
					Player(std::string namein);
	   				int get_amount();
	   				std::string get_name();
	   				int get_level();
	   				int get_goal();
	   				int get_score();
	   				void set_amount(int amount);
	   				void set_level(int format_level_display);
	    			void set_goal(int go);
	    			void set_score(int format_score_display);
	   				void set_lucky(int luckin);
	   				void handle_bets(Fl_Group* inner[37], Fl_Group* outer[9]);
       				void spin_wheel();	 
	   				bool is_error();
	   				int get_winner();
	   				int get_result();
	   				bool check_high();	     
};

#endif

