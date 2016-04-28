/*
Name: Bet_Calculator.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the member functions of the Bet_Calculator class.
*/

#include "Bet_Calculator.h"
#include <sstream>
#include "Message_Box.h"
#include "Useful_Functions.h"

/*
Accsessor method for the input field.

Returns: Array pointer to the input fields.
*/

Fl_Int_Input** Bet_Calculator::get_input(){

        return input;
}

/*
Accessor method for the output field. 

Returns: Array pointer to the output fields.
*/

Fl_Text_Display** Bet_Calculator::get_output(){

        return output;
}

/*
Call back function which is assigned to all int_input fields in this window.
The function gets the input from each of the fields and calculates the maximimum 
amount they can expect to win from that bet. This does not account for the
dependance of the outer bets on one another but does account for the dependance
of inner bets on one another. Does not account for different amounts of money
being bet on different singles. The results are then displayed in the Fl_Text_Displays
at the bottom of the window.

Parameter inps: A variable to hold the 11 input fields. 
Parameter inpstr: A variable that holds the string input obtained from the int input
              	  this is used in checking the size of the input to see if it is acceptable
Parameter input: An integer used to hold the current amount of money that had been bet this
              	 the possible winnings from this amount is added to payout. 
Parameter outs:	A variable to hold the two output fields.
Parameter multistr: A string to hold the number of singles being bet, its size is checked
                    to avoid incorrect input.
Parameter multi: Holds the number of singles being placed.
Parameter buff, buff2: The two buffers which are added to the two output fields. These are changed 
                   	   as the input fields are changed.
Parameter payout: Integer that is incremented to match the maximum payout.
Parameter total: Integer that is incremented to match the total amount of the bets.
Parameter correct: A boolean that is true when checked if the input is valid and false if it is not. 

Returns: Nothing.
*/

void Bet_Calculator::input_cb(Fl_Widget* w, void* v){
        
		static const int max_multiplier_number=37;
		static const int max_multiplier_size=2;
		static const int max_input_size=7;
        Fl_Int_Input** inps=((Bet_Calculator*)v)->get_input();
	    Fl_Text_Display** outs=((Bet_Calculator*)v)->get_output();
	    const char* str=inps[0]->value();
		std::string multistr =const_char_to_string(str);
		int multi= atoi(str);
		Fl_Text_Buffer* buff= new Fl_Text_Buffer();
	    Fl_Text_Buffer* buff2= new Fl_Text_Buffer();
		outs[0]->buffer(buff);
   	    outs[1]->buffer(buff2);
		const char* wrong= "Error: An incorrect\nvalue has been input";  
/*	  	   
The logical statements below deal with the input errors a user may make.
They remove cases when the input is negative, removes any possible integer
overflow by restricting the inputs to a maximum size of 7 except for the
multiplier field which is restricted to 2 as there cannot be more than 37
singles placed.
*/
		bool correct=true;
		int total=0;
		int payout=0;
		if(multi<0||multi>max_multiplier_number||multistr.size()>max_multiplier_size){

				correct=false;

		}else{
				const char* str2=inps[1]->value();
				std::string inpstr2=const_char_to_string(str2);
				int value=atoi(str2);
        		if(value<0||inpstr2.size()>max_input_size){
		
						correct=false;
				}else{
		
						if(multi!=0){
						
								total+=multi*value;
								payout+=36*value;
						}
						for(int i=2;i<11;i++){
		        				
								const char* str3=inps[i]->value();
								std::string inpstr3=const_char_to_string(str3);
								int input=atoi(str3); 	  	  	  	  	  	  
								if(input<0||inpstr3.size()>max_input_size){
						
										correct=false;
										break;
								}else{
						
										if(i<8){
				 						
	  	                						payout+=2*input;
	             						}else{ 
				  							
				         						payout+=3*input;											
										}
										total+=input;
         						}
						}
				}
		}
		 		
   		if(correct){
		 
         				buff->text(std::to_string(total).c_str());
   		  	    		buff2->text(std::to_string(payout).c_str());
   		}else{   
		  
      					buff->text(wrong);
          }
}

/*
The constructor for a Bet_Calculator window. It creates a window with
message boxes displaying what kind of bet the int input field next to it
is assigned to. The int input fields are for the user to enter the bet amount
they want to calculate the return for. There are two output fields at the
bottom of the window which display the total amount of all bets and the 
maximum return for that bet.

Returns: Nothing.
*/


Bet_Calculator::Bet_Calculator(int x, int y, int width, int height, const char* title):Inside_Window(x,y,width,height,title){

		const char* caption="";
   		for(int i=0;i<11;i++){
		
        		switch(i){
				
        				case 0: caption="No. of singles:"; break;
						case 1: caption="Single:"; break;
					    case 2: caption="1 to 18:"; break;	    
			     		case 3: caption="Even:"; break;
		         		case 4: caption="Black:"; break;   
		         		case 5: caption="Red:"; break;
		         		case 6: caption="Odd:"; break;
		         		case 7: caption="19 to 36:"; break;
		         		case 8: caption="1st 12:"; break;	    
		         		case 9: caption="2nd 12:"; break;     
		         		case 10: caption="3rd 12:"; break;	 
			    }
					 	
	    new Message_Box(0,i*height/12,width/2,height/12,caption);
	    input[i]=new Fl_Int_Input(width/2,i*height/12,width/2,height/12);
	    input[i]->callback(input_cb, this);
	    input[i]->when(FL_WHEN_CHANGED);
   		}
		
   		new Message_Box(0 ,(11*height)/12 ,width/4 ,height/12 ,"Money Bet:");
   		output[0]= new Fl_Text_Display(width/4 , (11*height)/12 ,width/4 ,height/12 );
 		new Message_Box(width/2, (11*height)/12, width/4 , height/12 ,"Maximum Return:");
   		output[1]= new Fl_Text_Display((3*width)/4,(11*height)/12,width/4 ,height/12 );
   		show();
} 

