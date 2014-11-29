#pragma once

#include "Textures.h"
#include "string.h"
#include "Window.h"

/**@brief a class for a menu choice*/
class MenuKey
{
private:
	/*choice texture*/
	Textures *key = new Textures(1);
public:
	/*
	Constructs the key
	Constructs the menu choice
	@param std::string the image file location
	@param window* the window to render to**/
	MenuKey(std::string, Window*);

	/**
	de-constructs the key
	de-constructs the menu choice*/
	~MenuKey();

	/**
	getter # the texture
	gets the texture
	@return Textures* the texture*/
	Textures* getPic();
};