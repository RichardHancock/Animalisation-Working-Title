#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#pragma once

/** 
@brief Creates a Window and Renderer

Handles all the initializations for SDL and plug-ins
*/
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

	/** 
	@brief Returns the renderer
	@returns SDL_Renderer* - SDL render object
	*/
	SDL_Renderer* getRenderer();

	/**
	@brief Returns the window
	@returns SDL_Window* - SDL window object
	*/
	SDL_Window*	getWindow();

private: 
	SDL_Window *window;
	SDL_Renderer *renderer;

};