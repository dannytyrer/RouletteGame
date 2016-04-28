/*
Name Highscore_List.h
Author Daniel Tyrer
Last Edited: 21/01/2015

This class is used for the implementation of the high score feature of the game.
This class is a linked list data structure which allows for fast insertion and
deletion in order that can not be achieved using an array due to the fact indexes must
be shifted to insert/delete.
*/

#ifndef Highscore_List_H
#define Highscore_List_H
#include "Score_Data.h"

class Highscore_List{

		private:
		
   				Score_Data head;
   				Highscore_List* tail;
   				bool is_empty;
		
   		public:
   
   				Highscore_List();
   				Highscore_List(const Score_Data head, Highscore_List* tailptr);
   		 	    Score_Data get_head();
   				Highscore_List* get_tail();
   				bool get_empty();
   				static Highscore_List* cons(const Score_Data dat, Highscore_List* tailptr);
   				static Highscore_List* empty();
   				Highscore_List* insert(const Score_Data dat);
   				Highscore_List* delete_last();
   				bool equals(Highscore_List* list);
   				std::string to_string();
   				static void save_high(Highscore_List* list);
   				static Highscore_List* read_high();
   				static bool check_high(const Score_Data dat);
				~Highscore_List() { delete tail;};	
};

#endif

