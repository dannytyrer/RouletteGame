/*
Name: Useful_Functions.cpp
Author: Daniel Tyrer
Last Edited: 21/01/2015

This file implements some useful functions to avoid code duplication.

*/

#include "Useful_Functions.h"
#include <sstream>

/*
This function converts a const char* to a std::string. Based off code found at
http://stackoverflow.com/questions/8126498/how-to-convert-a-const-char-to-stdstring

Returns: std::string representation of the input const char.
*/

std::string const_char_to_string(const char* str){

		return std::string(str);
}

/*
This function converts an integer to a std:string. Based off code found at 
http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c

Returns: std::string representation of the input int. 
*/

std::string int_to_string(int num){

        std::stringstream conv;
		conv<<num;
		std::string res= conv.str();
		return res;

}

/*
This function converts an integer to a const char*. Based of code found at
http://stackoverflow.com/questions/25848826/conversion-from-int-to-c-string-const-char-fails

Returns: const char* representation of the input int. 
*/


const char* int_to_const_char(int num1){

		std::string res1= int_to_string(num1);
		const char* newconstchar= res1.c_str();
		return newconstchar;
}

/*
This function checks whether an input integer is a red number on a roulette table using the binary search
algorithm on an array whose values are known to be red.

Returns: True if the number is red, false otherwise.
*/

bool is_red(int num){

        static const int red_numbers [18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
		int left=0, right=17, mid;
		while(left<right){

   				mid=(left+right)/2;
   				if(num>red_numbers[mid]){
      					left=mid+1;
 		  	    }else{
        				right=mid;
			    }
		}
		
		if(red_numbers[left]==num){
   
   				return true;
   		}else{
   				return false;
  		}
}

