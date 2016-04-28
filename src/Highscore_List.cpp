/*
Name: Highscore_List.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements the recursive data structure Highscore_List.
*/

#include "Highscore_List.h"
#include <fstream>
#include <iostream>

/*
This function produces a std:string representation of the list to store
in a file.

Returns: A std::string representation of the Highscore_List. 

*/

std::string Highscore_List::to_string(){

   		if(is_empty){
     
      			return "";
        }else if(tail->get_empty()){
		
      			return head.to_string();
   		} else{
		
      			return (tail->to_string())+"\n"+head.to_string();
   }
}

/*
This function reads the high scores from a file into a Highscore_List.

Returns: The Highscore_List representation of the highscore.dat file.
*/

Highscore_List* Highscore_List::read_high(){
        
  		std::ifstream file;
   		file.open("highscore.dat");
   		Highscore_List* high= new Highscore_List();
   		Score_Data dat;
   		std::string nme;
   		int tmp;
   		if(file.is_open()){
      
	  			while(file>>nme){
      
   	     				file>>tmp;
         				Score_Data dat=Score_Data(tmp,nme);
         				high=(high->insert(dat));      
   			    }
				
	  	file.close();
   		}else{
 				
				perror("highscore.dat");
	    }
   
   		return high; 
}

/*
This function saves the input Highscore_List* to file as the new high scores.

Returns: Nothing.
*/

void Highscore_List::save_high(Highscore_List* l1){
   
   		std::ofstream file;
   		file.open("highscore.dat");
   		if(file.is_open()){
      			file<<(l1->to_string());
	  			file.close();
   		}else{
   				
				perror("highscore.dat");
	  	}
}

/*
This function checks if two Highscore_Lists are equal. Equal here means that the scores
of the two Highscore_Lists are in the same order. In the context of this project this is 
sufficient. If someone wanted a complete match of Score_Data objects in the right positions
the name field of the Score_Data objects would also have to be checked.

Returns: True if the Highscore_Lists are equal, false otherwise.
*/

bool Highscore_List::equals(Highscore_List* list){

   		if(is_empty&&list->get_empty()){
   
   				return true;
   		}else if(is_empty||list->get_empty()){
   
     		  	return false; 
   		}else if(head.get_score()==(list->get_head()).get_score()){
   
      			return tail->equals(list->get_tail());
   		}else{
      
	  			return false;
   		}
}

/*
Accessor method for the tail of the Highscore_List

Returns: Pointer to the next node of the Highscore_List.
*/

Highscore_List* Highscore_List::get_tail(){

		return tail;
}

/*
Accessor method for the head of the Highscore_List.

Returns: The Score_Data object that is the current node in the list.
*/

Score_Data Highscore_List::get_head(){

   		return head;
}

/*
This function creates a new empty list to reduce the amount of code writing
involved- not as many new statements to write.

Returns: A new empty Highscore_List*
*/

Highscore_List* Highscore_List::empty(){

   		return new Highscore_List();
}

/*
Deletes the element in the Highscore_List with the lowes score, this is used
to keep the Highscore_List a constant size.

Returns: A new Highscore_List with the last element deleted.
*/

Highscore_List* Highscore_List::delete_last(){

  		 return new Highscore_List(tail->get_head(),tail->get_tail());
}

/*
Inserts a new Score_Data object into the list in order. The order is from
lowest score to highest score.

Returns: A new Highscore_List* with the new Score_Data object inserted.
*/

Highscore_List* Highscore_List::insert(Score_Data dat){
         
   		if(is_empty){
		
      			return new Highscore_List(dat, empty());
   		}else if(dat.get_score()>head.get_score()){
   
       			return new Highscore_List(head,tail->insert(dat));
   		}else{
   
       			return new Highscore_List(dat,new Highscore_List(head,tail));
   		}
}

/*
Accessor method for the field is_empty.

Returns: is_empty saying whether the Highscore_List is empty or not. True - Empty
         False - Not empty.
*/

bool Highscore_List::get_empty(){

   		return is_empty;
}

/*
This function constructs a new Highscore_List object, this reduces the number of times
the statement new has to be written.

Returns: A new Highscore_List* with dat as the head and tail ptr as the tail. 
*/

Highscore_List* Highscore_List::cons(Score_Data dat, Highscore_List* tailptr){

   		return new Highscore_List(dat, tailptr);
}

/*
Constructs an empty Highscore_List object.

Returns: Nothing.
*/

Highscore_List::Highscore_List(){

   		is_empty=true;
}

/*
Constructs a new Highscore_List with dat as the head and tailptr as the tail.

Return: Nothing.
*/

Highscore_List::Highscore_List(Score_Data dat, Highscore_List* tailptr){

  		head=dat;
  		tail=tailptr;
  		is_empty=false;
}


