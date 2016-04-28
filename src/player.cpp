/*
Name: Player.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class implements the member functions of the Player class.
*/

#include "Player.h"
#include <iostream>
#include "Innerbet_Window.h"
#include "Outerbet_Window.h"
#include "Score_Data.h"
#include "Highscore_List.h"
#include "Useful_Functions.h"

/*
This function checks whether the player object has made the high scores or not at the end of the game.

Parameter list: The highscore list read from file.
Parameter templist: Initialised to the high score list from file. Used to compare the list with the new score inserted
                    to determine whether the score made the high list.

Return: True if the score made the high scores, false otherwise.					
*/

bool Player::check_high(){
   
   		Highscore_List* list=Highscore_List::read_high();
   		Highscore_List* templist=list;
   		Score_Data dat=Score_Data(score, name);
   		list=(list->insert(dat));
   		list=(list->delete_last());
   		if(list->equals(templist)){
   
      			return false;
   		}else{
   
      			Highscore_List::save_high(list);
	  			return true;
   		}   
}

/*
Accessor for the field number.

Returns: The winning number of the bet.
*/

int Player::get_winner(){
   
   		return number;
}

/*
Accessor for the field result.

Returns: The field result.
*/

int Player::get_result(){
   
  	 	return result;
}

/*
Accessor for the amount field.

Returns: The amount field.
*/
	   
int Player::get_amount(){
   		
		return amount;   
}

/*
Accessor for the name field.

Returns: The name of the player.
*/

std::string Player::get_name(){
   		
		return name;
}

/*
Accessor for the level field.

Returns: The current level the player is on.
*/

int Player::get_level(){
   		
		return level;
}

/*
Accessor for the error field.

Returns: The error field.
*/ 

bool Player::is_error(){

   		return error;
}

/*
Accessor for the goal field.

Returns: The goal field.
*/

int Player::get_goal(){
   		
		return goal;
}

/*
Accessor for the score field.

Returns: The score field.
*/

int Player::get_score(){
   		
		return score;
}

/*
Mutator for the amount field.

Returns: Nothing.
*/

void Player::set_amount(int newam){
   		
		amount=newam;
}

/*
Mutator for the level field.

Returns: Nothing.
*/

void Player::set_level(int newlev){
   		
		level=newlev;
}

/*
Mutator for the goal field.

Returns: Nothing.
*/

void Player::set_goal(int newgo){
   		
		goal=newgo;
}

/*
Mutator for the score field.

Returns: Nothing.
*/
 
void Player::set_score(int newsco){

   		score=newsco;
}

/*
Mutator for the result field.

Returns: Nothing.
*/

void Player::set_lucky(int resuin){
   
   		result=resuin;
}

/*
This function simulates the spin of a roulette wheel. It selects a random number
from within the range 0-36. It then updates the number field with the winning number.

Returns: Nothing.
*/

void Player::spin_wheel(){
   		
		number=rand()%37;
}

/*
This function checks to see if the next level has been reached and updates the score 
accordingly.

Returns: Nothing.
*/

void Player::check_level(){

   		if(amount>=goal){
     			score=100*level;
     			level++;
				int goaltmp=goal;
	 			goal=(goal*1.5*level); 
  		}
}

/*
This function handles the bets input in the Bet_Window. It takes the inner and outer bets as arguments
and evaluates whether each of the bets have won or not. This then alters the result variable to match the result
of the bet.

Parameter error: Initialised to false, is changed to true if there is something wrong with what the user input.
Parameter before_amount: The amount the user has bet before the bet has come in. If this value at the end of the
						 function is less than 0 there has been an error as there is not enough funds.
Parameter amount_temp: This is a temporary variable that is incremented and decremented to match the amount after
					   the bet has come in. This is used in assigning the value of the result to be sent to the 
					   Game_Window to update the win display.
Parameter bet_amount:  Variable used to hold the bet amount whilst the payout is being calculated.
Parameter outer: An array holding the Fl_Group* that contains the Int_Input field for outer bets. A different type
                 of bet is found at a different index of the array.
Parameter inner: An array holding the Fl_Group* that contains the Int_Input field for inner bets. The bet number
                 is found as the current index of the array.
Parameter start_index: Indexes greater than this correspond to dozens and have a payout of 2/1.	   	   	   	    
				 	 	 	 	 	    
*/

void Player::handle_bets(Fl_Group* inner[37], Fl_Group* outer[9]){  
      
   		error=false;
   		spin_wheel();
   		before_amount=amount;
   		int amounttmp=amount;
		static const int start_index=6;
		
		/*
		Cycle through each element of the outerbet array. Check that it is a valid
		input. The elements where i>6 will give a payout of 2 times the amount that was bet as is 1/1 and 
		the others give a payout of 3 times the amount that was bet as is 2/1.
		Evaluate if the bet was won or not, if it was increment the amounttmp by the payout defined earlier,
		if not, continue.
		*/
		
   		for(int i=0; i<9; i++){
	
      		    const char* str=((((Outerbet_Window*)outer[i])->get_field())->value());	   	   	   
				std::string outerstr=const_char_to_string(str);
				int bet_amount=atoi(str);
	  			if(bet_amount>=0&&outerstr.size()<8){
				        
	     				before_amount-=bet_amount;
	     				amounttmp-=bet_amount;
	     				int payout;
	     				if(i<start_index){
						
		    					payout=2*bet_amount;
		 				}else{
		 
		    					payout=3*bet_amount;
		 				}
		 
		 				switch(i){
						
								case 0:if(number>0&&number<=18){ amounttmp+=payout; } break;   //Number is in the range 1-18
								case 1:if(number%2==0&&number!=0){ amounttmp+=payout; } break; //Number is even
								case 2:if(!is_red(number)&&number!=0){ amounttmp+=payout; } break; //Number is black
								case 3:if(is_red(number)){ amounttmp+=payout; } break; //Number is red
								case 4:if(number%2!=0){ amounttmp+=payout; } break;     //Number is odd
								case 5:if(number>18&&number<=36){ amounttmp+=payout; } break; //Number is in the range 19-36
								case 6:if(number>0&&number<=12){ amounttmp+=payout; } break;  //Number is in the first 12
								case 7:if(number>12&&number<=24){ amounttmp+=payout; } break; //Number is in the second 12
								case 8:if(number>24&&number<=36){ amounttmp+=payout; } break; //Number is in the third 12
						}
				 }else{
				 
				 		error=true;
						return;
				 }
 		}
		
		/*
		Cycle through all the elements of the inner bet array, if the winning number was picked, increment
		the amounttmp by the payout of 36 times the bet amount as the payout is 35/1. If the input was not
		valid change error to true.
		*/
		
   		for(int i=0; i<37; i++){
				
				const char* str2=(((Innerbet_Window*)inner[i])->get_field())->value();
				std::string innerstr=const_char_to_string(str2); 
				int bet_amount=atoi(str2);
      			
				if(bet_amount>=0&&innerstr.size()<8){
	 		 		before_amount-=bet_amount;
	  				amounttmp-=bet_amount;
      				if(i==number){
	    					amounttmp+=36*bet_amount;
	  				}
				}else{
					
						error=true;
						return;
				}
    	}
	
   		set_lucky((amounttmp-amount)); 
		if(before_amount>=0){
		
	   			if(result!=0){
				
	      				amount=amounttmp;
					    if(result>0){
						
								if(level<11){
	      								
										score+=(11-level)*(amount/100);
								}else{
										score++;
								}	 	 	 	 
						}	 	 
	      				check_level();
	   			}
		}else{
	   
	    		error=true;
		}
}

/*
Constructor for the Player Class. All of the variables are initialised to match the state
of a new game.

Returns: Nothing.
*/

Player::Player(std::string namein){
   
   		name=namein;
   		level=1;
   		score=0;
   		amount=100;
   		goal=150;
   		result=0;
}

/*
Empty constructor needed to store a current_player object as a member variable.

Returns: Nothing.
*/

Player::Player(){


}

