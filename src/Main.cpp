/*
Name: Main.cpp
Author: Daniel Tyrer
Last Modified 22/01/2015

File to hold the main function.
*/

#include <Fl/Fl.h>
#include "Startup_Window.h"

int main(){

   		new Startup_Window(430, 100, 500, 500, "Roulette");
   		return(Fl::run());
}

