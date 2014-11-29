#pragma once

#include <SDL.h>
#include "menuKey.h"

/**
@brief a class for the menu*/
class Menu
{
private:
	/*variables*/
	MenuKey* key[2];
	MenuKey* keyH[2];
	Textures* background = new Textures(1);
	int highlightedKey;
	SDL_Rect b;
	bool lastUp, lastDown;
public:
	/**
	constructs the menu
	constructs the menu
	@param Window* the window to render to*/
	Menu(Window*);

	/**
	deconstructs the menu
	deconstrucst the menu*/
	~Menu();

	/**
	displays the menu
	displays the menu to the window
	@param Window* the window to render to*/
	void displayMenu(Window*);

	/**
	updates the menu
	updates the menu
	@param bool the up command
	@param bool the down command
	@param bool the enter command
	@return bool if the enter has been hit*/
	bool updateMenu(bool, bool, bool);

	/**
	Getter # highlited key
	gets the value of the higlighted key
	@return int the value of the highlighted key*/
	int getHighlight();
};