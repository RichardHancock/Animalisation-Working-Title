#include "inputManager.h"

InputManager::InputManager()
{
	/*boolean key responce commands*/
	cmd_forwards = cmd_backwards = cmd_left = cmd_right = cmd_enter = cmd_rMouse = cmd_lMouse = false;
	mouse.x = 0;
	mouse.y = 0;
}

InputManager::~InputManager()
{
}

bool InputManager::updateInput()
{

	/*create the event variable*/
	SDL_Event incomingEvent;

	/*run loop while SDL contains an event*/
	while (SDL_PollEvent(&incomingEvent))
	{
		switch (incomingEvent.type)
		{

		case SDL_QUIT:

			return true;
			break;

		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{

			case SDLK_ESCAPE:
				return true;
				break;
			case SDLK_UP:
				cmd_forwards = true;
				break;
			case SDLK_DOWN:
				cmd_backwards = true;
				break;
			case SDLK_LEFT:
				cmd_left = true;
				break;
			case SDLK_RIGHT:
				cmd_right = true;
				break;
			case SDLK_w:
				cmd_forwards = true;
				break;
			case SDLK_s:
				cmd_backwards = true;
				break;
			case SDLK_a:
				cmd_left = true;
				break;
			case SDLK_d:
				cmd_right = true;
				break;
			case SDLK_RETURN:
				cmd_enter = true;
				break;

			}
			break;

		case SDL_KEYUP:
			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_UP:
				cmd_forwards = false;
				break;
			case SDLK_DOWN:
				cmd_backwards = false;
				break;
			case SDLK_LEFT:
				cmd_left = false;
				break;
			case SDLK_RIGHT:
				cmd_right = false;
				break;
			case SDLK_w:
				cmd_forwards = false;
				break;
			case SDLK_s:
				cmd_backwards = false;
				break;
			case SDLK_a:
				cmd_left = false;
				break;
			case SDLK_d:
				cmd_right = false;
				break;
			case SDLK_RETURN:
				cmd_enter = false;
				break;
			}
			break;

		case SDL_MOUSEMOTION:
			mouse.x = incomingEvent.motion.x;
			mouse.y = incomingEvent.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (incomingEvent.button.button)
			{
			case SDL_BUTTON_LEFT:
				cmd_lMouse = true;
				break;
			case SDL_BUTTON_RIGHT:
				cmd_rMouse = true;
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (incomingEvent.button.button)
			{
			case SDL_BUTTON_LEFT:
				cmd_lMouse = false;
				break;
			case SDL_BUTTON_RIGHT:
				cmd_rMouse = false;
				break;
			}
			break;
		}
	}
	return false;
}

bool InputManager::getForwards()
{
	return cmd_forwards;
}

bool InputManager::getBackwards()
{
	return cmd_backwards;
}

bool InputManager::getRight()
{
	return cmd_right;
}

bool InputManager::getLeft()
{
	return cmd_left;
}

bool InputManager::getEnter()
{
	return cmd_enter;
}

bool InputManager::getRMouse()
{
	return cmd_rMouse;
}

bool InputManager::getLMouse()
{
	return cmd_lMouse;
}

float InputManager::getMouseX()
{
	return mouse.x;
}

float InputManager::getMouseY()
{
	return mouse.y;
}
