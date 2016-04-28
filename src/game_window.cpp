/*
Name: Game_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Game_Window class.
*/

#include "Game_Window.h"
#include "Score_Window.h"
#include "Bet_Window.h"
#include "Roulette_Menu.h"
#include "Endgame_Window.h"
#include "Quit_Window.h"
#include <iostream>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include "JPEG_Image_Box.h"
#include "Useful_Functions.h"
#include <ctime>

/*
Definitions for use in the animation of the wheel.

Parameter TOTALW: The total number of wheel images.
Parameter RATEW: The rate at which the images are shown.
Parameter jpgs2: An array to hold the images when they have been stored in memory.
Parameter wheelb: The box where the animation is to take place is redrawn every time
              	  a different image is put up.
Parameter DEFAULT_*: The default variables for the start of a game.	   	   	   	     
*/

#define TOTALW 36
#define RATEW 0.002
#define DEFAULT_SCORE 0
#define DEFAULT_AMOUNT 100
#define DEFAULT_LEVEL 1
#define DEFAULT_GOAL 150
Fl_JPEG_Image* jpgs2[36];
JPEG_Image_Box* wheelb;

/*
This function restarts the game by setting the current_players values to their
default. The function then updates the Score_Window to match the current state of 
the game. It removes anything from the winner display.

Returns: Nothing.
*/

void Game_Window::restart_game(){
  
        current_player.set_amount(DEFAULT_AMOUNT);
        current_player.set_score(DEFAULT_SCORE);
        current_player.set_goal(DEFAULT_GOAL);
        current_player.set_level(DEFAULT_LEVEL);
        ((Score_Window*) score_display)->update(current_player);
        set_winner(NULL,NULL,NULL,2,NULL);
}

/*
Loads the images needed for the wheel spinning animation. Code is adapted from that
displayed on "http://seriss.com/people/erco/fltk/" under the header animation example.

Returns: 1 if the file does not load correctly, 0 if it does. 
*/

int Game_Window::load_wheel(int noim){

        for(int t=0;t<noim;t++){
		
	            char filename[80];
	            sprintf_s(filename, "wheel%d.jpg",t+1);
	            jpgs2[t]= new Fl_JPEG_Image(filename);
		        if(jpgs2[t]->w()==0){
			        perror(filename);
				    return 1;
       	        }
        }
		
	    return 0;
}

/* 
Mutator for the score_display field.

Returns: Nothing.
*/

void Game_Window::set_score(Fl_Group* scorein){

        score_display=scorein;
}

/*
Accessor for the current_player field.

Returns: The Player object current_player.
*/

Player Game_Window::get_player(){

        return current_player;
}

/*
Mutator for the current_player field.

Returns: Nothing.
*/

void Game_Window::set_player(Player pin){

        current_player=pin;
}

/*
Accessor for the bet_display field

Returns: The bet_display field. 
*/

Fl_Group* Game_Window::get_bet(){

        return bet_display;
}

/*
Accessor for the score_display field.

Returns: The score_display field.
*/

Fl_Group* Game_Window::get_score(){

        return score_display;
}

/*
Accessor for the win_display field.

Returns: The win_display field.
*/

Fl_Text_Display* Game_Window::get_winner(){

        return win_display;
}

/*
This function constructs and updates the win_display field.

Parameter lucky: If lucky is less tha 0 the bet has been lost, if it is greater
                 than zero the bet has been won and if it is zero the bet has drawn
			     even. The magnitude of lucky is how much th player has won/lost.
			     This is displayed in the text field.
Parameter first: This parameter is tested to see if the window needs to be constructed
                 or simply updated.	   	   	    

*/

void Game_Window::set_winner(int win, int width, int height, int first, int lucky){
 	
        Fl_Text_Buffer* buff=new Fl_Text_Buffer();
        if(first==1){
		 
                win_display=new Fl_Text_Display((3*width/4)-(width/14),(3*height/4)-50,width/7,50);
	            win_display->buffer(buff);
                buff->text("");
        }else if(first==2){
                
				win_display->buffer(buff);
	            buff->text("");
        }else{
               
			    win_display->buffer(buff);
                std::string result=int_to_string(win);
                std::string str="The winner is: ";
                str.append(result);
	            std::string message;
	            
	  
	            if(lucky<0){ 
	                    
						lucky=lucky*-1;
	                    message="\nBetter luck next time!\nYou lost: £";
	            }else{
				
	                    if(lucky>0){
	                  
					            message="\nCongratulations you won!\nYou won: £";
	                    }else{
	                  
					            message="\nYou drew even!\nYou won: £";
	                    }
	            }
				
	            std::string res2=int_to_string(lucky); 
	            message.append(res2);
	            str.append(message);
	            const char* l=str.c_str();
	            buff->text(l);
        }
}  

/*
This is the callback function for the quit window. It opens a new Quit_Window.

Returns: Nothing.
*/

void Game_Window::quit_cb(Fl_Widget* w, void* v){

        Quit_Window* quit= new Quit_Window(500, 200);
}

/*
This function runs the animation of the wheel spinning. When the wheel has spun three times
the function is exited and is not called until the place button is clicked again. The Game_Window
is then updated with the result of the bet. If the user has exhausted all of their funds then
an Endgame_Window is opened notifiying them of this and asking if they want to play again.

Adapted from code found at "http://seriss.com/people/erco/fltk/" under the header animation example.

Parameter p: Variable to hold the current player.
Parameter x: Acts as a counter to display the correct image and is tested to exit the function. Is incremented
             by 1 every pass of the function.
*/

void Game_Window::run_animation_cb(void* v){
       
	    static int x=1;
        wheelb->image(jpgs2[x++ % TOTALW]);
        wheelb->redraw();
        if(x>108){
   
                Player p=((Game_Window*)v)->get_player();
                ((Game_Window*)v)->set_winner(p.get_winner(),NULL,NULL,0,p.get_result());
	            ((Score_Window*)((Game_Window*)v)->get_score())->update(p);
	            ((Game_Window*)v)->redraw();
				(((Game_Window*)v)->get_place_button())->activate();
	            x=1;
				if(p.get_amount()==0){
	     
		        const char* message;
	            if(p.check_high()){
				
		                message="Congratulations! You have made the high scores list\n Do you want to play again?";         
				}else{
		           
				        message="Unlucky, you did not make the high scores list\n Do you want to play again?";
		        }
				
		        ((Game_Window*) v)->set_over(new Endgame_Window(500,200,"Game_Window Over!", message, ((Game_Window*)v)));
	    }      
         }else{
       
	            Fl::repeat_timeout(RATEW, run_animation_cb, v);
         }
}

/*
Accessor function for the place button.

Returns: The place_button field casted to an Fl_Button*. 
*/

Fl_Button* Game_Window::get_place_button(){

   		return ((Fl_Button*) place_button);
}

/*
This is the callback function for the place bet button.

This function deactivates the button, evaluates the bets and then runs the animation. If there
is an error in the input, a notification window is opened notifying the user of the error and then activates
the button again.

Returns: Nothing. . 
*/

void Game_Window::place_bet_cb(Fl_Widget* w, void* v){
       
		((Fl_Button*)w)->deactivate();
        Player p=((Game_Window*) v)->get_player();
	    p.handle_bets(((Bet_Window*)(((Game_Window*) v)->get_bet()))->get_inner_bets(),
	    ((Bet_Window*)(((Game_Window*) v)->get_bet()))->get_outer_bets());
	    ((Game_Window*) v)->set_player(p);	  
	    if(p.is_error()){
		
	            Notification_Window* err=new Notification_Window(500,200, "Error",
				                                                "An incorrect value has been input, please try again.\n(You may not have the funds for the bet)",0);
	    		((Fl_Button*)w)->activate();
		}else{
	          
			    Fl::add_timeout(RATEW, run_animation_cb, v);
	    }
	    
}

/*
Mutator for the over field. This is used to open up a new Endgame_Window when the players amount has
gone to 0. This is used to open a new Endgame_Window.

Returns: Nothing.
*/

void Game_Window::set_over(void* overin){

        over=overin;
}

/*
Accessor method for the over field. This is used to close the Endgame_Window if the user decides to play
again.

Returns: The over field.
*/

void* Game_Window::get_over(){

        return over;
}

/*
Constructor for the Game_Window. This seeds the random number generator witht he current time so that the random
number generated is different every time the game is opened. The images for the wheel animation are loaded into
memory. The current_player field is set with a new Player object with the name given by s. All widgets contained
on the window are constructed.

Returns: Nothing. 
*/


Game_Window::Game_Window(int x, int y, int width, int height , const char *title, std::string s):Inside_Window(x,y,width,height,title){

        srand(time(NULL));
	    begin();
	    load_wheel(TOTALW);
	    set_player(Player(s));
	    bet_display= new Bet_Window(0,100,width/2,height-100);	  
        score_display= new Score_Window(0,0,width/2,100,get_player());
        place_button= new Fl_Button((3*width/4)-50,3*height/4,100,50,"Place Bet");
	    place_button->callback(place_bet_cb, this);
	    ((Fl_Button*)place_button)->shortcut(FL_Enter);
	    Fl_Button* quitButton= new Fl_Button(width-100,height-50,100,50,"Quit");
        quitButton->callback(quit_cb,this);
	    JPEG_Image_Box* wheelbox=new JPEG_Image_Box(3*width/4-(352/2),(height/4)-50,352,352,"wheel1.jpg");
	    wheelb=wheelbox;
	    set_winner(NULL,width, height, 1, NULL);
	    Roulette_Menu* menu=new Roulette_Menu(width-100,0,100,50,"Menu");
        show();
		end();    
}


