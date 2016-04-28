/*
Name: Score_Window.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Score_Window class.
*/

#include "Score_Window.h"
#include <sstream>
#include "Useful_Functions.h"

/*
Accessor for the name_display field.

Returns: The name_display field.
*/

Fl_Text_Display* Score_Window::get_name_display(){

   		return name_display;
}

/*
Accessor for the level_display field.

Returns: The level_display field.
*/

Fl_Text_Display* Score_Window::get_level_display(){

   		return level_display;
}

/*
Accessor for the score_display field.

Returns: The score_display field.
*/

Fl_Text_Display* Score_Window::get_score_display(){

   		return score_display;
}

/*
Accessor for the amount_display field.

Returns: The amount_display field.
*/

Fl_Text_Display* Score_Window::get_amount_display(){

   		return amount_display;
}

/*
Accessor for the target_display field.

Returns: The target_display field.
*/

Fl_Text_Display* Score_Window::get_target_display(){

   		return target_display;
}

/*
This function initialises the name_display. 

Returns: Nothing.
*/

void Score_Window::format_name_display(std::string name,int width,int height){
   
   		std::string str="Welcome to the \ntable ";
   		str.append(name);
   		const char* l=str.c_str(); 
   		Fl_Text_Buffer* buff = new Fl_Text_Buffer();
   		name_display = new Fl_Text_Display(0, height/4, width/5,height/2);
   		name_display->buffer(buff);        	    
   		buff->text(l);
}

/*
This function initialises the level_display if first is true. It updates
it with the current level if first is false. This check is put in to reduce
code duplication.

Returns: Nothing.
*/

void Score_Window::format_level_display(int level, int width, int height, bool first){
   
		std::string res=int_to_string(level);
   		std::string str="Level: ";
   		str.append(res);
   		const char* l=str.c_str();
   		Fl_Text_Buffer* buff = new Fl_Text_Buffer();
   		if(first){
      			
				level_display = new Fl_Text_Display((width)/5, height/4, width/5,height/2);
   		}
		
   		get_level_display()->buffer(buff);      	
   		buff->text(l);
}

/*
This function initialises the score_display if first is true. It updates
it with the current score if first is false. This check is put in to reduce
code duplication.

Returns: Nothing.
*/

void Score_Window::format_score_display(int score, int width, int height, bool first){
        
   		std::string res=int_to_string(score);
   		std::string str="Your current score \nis: ";
   		str.append(res);
   		const char* l=str.c_str();
   		Fl_Text_Buffer* buff = new Fl_Text_Buffer();
   		if(first){
      			score_display = new Fl_Text_Display((2*width)/5, height/4, width/5,height/2);
   		}
   				score_display->buffer(buff);        	
   				buff->text(l);
}

/*
This function initialises the amount_display if first is true. It updates
it with the current amount if first is false. This check is put in to reduce
code duplication.

Returns: Nothing.
*/

void Score_Window::format_amount_display(int amount, int width, int height, bool first){
   	
   		std::string res=int_to_string(amount);
   		std::string str="Your balance\nis: £";
   		str.append(res);
   		const char* l=str.c_str();
   		Fl_Text_Buffer* buff = new Fl_Text_Buffer();
   		if(first){
      			amount_display = new Fl_Text_Display((3*width)/5, height/4, width/5,height/2);
   		}
   				amount_display->buffer(buff);        	   
   				buff->text(l);
}

/*
This function initialises the targer_display if first is true. It updates
it with the current target if first is false. This check is put int to reduce
code duplication.

Returns: Nothing.
*/

void Score_Window::format_target_display(int target, int width, int height, bool first){
       
   		std::string res= int_to_string(target);
   		std::string str="Your target\nis: £";
   		str.append(res);
   		const char* l=str.c_str();
   		Fl_Text_Buffer* buff = new Fl_Text_Buffer();
   		if(first){
      			
				target_display = new Fl_Text_Display((4*width)/5, height/4, width/5,height/2);   
   		}
   
   		target_display->buffer(buff);        	    
   		buff->text(l);
}

/*
This function updates the Score_Window and is called whenever a bet is made.

Returns: Nothing.
*/

void Score_Window::update(Player pin){
   
   		format_level_display(pin.get_level(),NULL,NULL,false);
   		format_score_display(pin.get_score(),NULL,NULL,false);
   		format_amount_display(pin.get_amount(),NULL,NULL,false);
   		format_target_display(pin.get_goal(),NULL,NULL,false);  
}

/*
Constructs the Score_Window.

Returns: Nothing.
*/

Score_Window::Score_Window(int x, int y, int width, int height, Player person):Inside_Window(x,y,width,height,""){
   
   		begin();
   		format_name_display(person.get_name(),width,height);
   		format_level_display(person.get_level(),width,height, true);
   		format_score_display(person.get_score(),width,height,true);
   		format_amount_display(person.get_amount(),width,height,true);
   		format_target_display(person.get_goal(),width,height,true);
   		show();
   		end();
}

