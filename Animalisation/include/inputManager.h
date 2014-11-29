#pragma once

#include <SDL.h>
#include "Vec2.h"

/**
@brief creates the manager for the SDL inputs*/
class InputManager
{
private:
	/*command varaibles*/
	bool cmd_forwards, cmd_backwards, cmd_left, cmd_right, cmd_enter, cmd_rMouse, cmd_lMouse;
	Vec2 mouse;
public:
	/**
	Constructs a imput manager object
	Constructs the imput manager*/
	InputManager();

	/**
	De-constructs a imput manager object
	De-constructs the imput manager*/
	~InputManager();

	/**
	Updates input
	Updates the input commands and returns a bool that relates to quiting the application*/
	bool updateInput();

	/**
	Getter # forwards command
	Get forwards command*/
	bool getForwards();

	/**
	Getter # backwards command
	Get backwards command*/
	bool getBackwards();

	/**
	Getter # right command
	Get right command*/
	bool getRight();

	/**
	Getter # left command
	Get left command*/
	bool getLeft();

	/**
	Getter # enter command
	Get enter command*/
	bool getEnter();

	/**
	Getter # right mouse command
	Get right mouse command*/
	bool getRMouse();

	/**
	Getter # left mouse command
	Get left mouse command*/
	bool getLMouse();

	/**
	Getter # mouseX
	Get mouseX*/
	float getMouseX();

	/**
	Getter # mouseY
	Get mouseY*/
	float getMouseY();
};

