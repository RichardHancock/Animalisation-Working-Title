#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#pragma once

class Window
{
public:
	/**
	Creates a window and renderer

	@param char* - Name of the window
	@param int - Window width
	@param int - Window height
	*/
	Window(char*, int, int);
	
	~Window();

	SDL_Renderer* getRenderer();
	SDL_Window*	getWindow();

private: 
	SDL_Window *window;
	SDL_Renderer *renderer;

};