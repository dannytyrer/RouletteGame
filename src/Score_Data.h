/*
Name: Score_Data.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to store the data, in a convenient object, that is required for checking the high scores list
and saving to it. This includes the name of the player and the score they achieved. 

Parameter score: the players score
Parameter name: the players name.

*/

#ifndef Score_Data_H
#define Score_Data_H
#include "Player.h"

class Score_Data{
   
   		private:
      			int score;
	  			std::string name;

   		public:
       
       			int get_score();
	   			Score_Data();
	   			Score_Data(Player p);
	   			Score_Data(int score, std::string name);
				virtual ~Score_Data() {};
	   			std::string to_string();   
};

#endif


