/*
Name: Score_Data.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class implements the member functions of the Score_Data class.
*/

#include "Score_Data.h"
#include "Player.h"
#include <sstream>
#include "Useful_Functions.h"

/*
This function creates a string representation of the Score_Data object

Parameter begin: Temporary variable used for appending the score to the name.

Returns: A std::string representing the Score_Data class.
*/

std::string Score_Data::to_string(){
   
   		std::string begin=name;
   		begin.append(" ");
   		std::string res=int_to_string(score);
   		begin.append(res);
   		return begin;
}

/*
Accessor method for the score field.

Returns: The score field.
*/

int Score_Data::get_score(){

   		return score;
}

/*
Empty constructor

*/

Score_Data::Score_Data(){

		score=NULL;

}

/*
Constructor for a Score_Data object. Uses the player to initialise its values.

Returns: Nothing.
*/

Score_Data::Score_Data(Player p){

   		score=p.get_score();
   		name=p.get_name();
}

/*
Constructor for a Score_Data object. Uses the int scorein and std::string to initialise
its values.

Returns: Nothing.
*/

Score_Data::Score_Data(int scorein, std::string namein){

   		score=scorein;
   		name=namein;
}

