/*
Name: Outside_Window.h
Author: Daniel Tyrer
Last Edited: 21/01/2015

This class is used to create a black window. Any window before log in and any pop
up windows inherit from this class to avoid code duplication.
*/

#ifndef Outside_Window_H
#define Outside_Window_H
#include <FL/Fl_Window.H>

class Outside_Window : public Fl_Window {

public:
	Outside_Window(int x, int y, int width, int height, const char* title);
	Outside_Window(int width, int height, const char* title);
	virtual ~Outside_Window() {};
};

#endif

