#include <iostream>
#include "Window.h"
#include "Textures.h"
#include "inputManager.h"

//Constants
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

//Globals
Window* window = new Window("Animalisation", WIN_WIDTH, WIN_HEIGHT);
InputManager* in = new InputManager();

//Function Prototypes
int main();



int main(int argc, char **argv)
{
	if (!window)
	{
		return -1;
	}

	Textures text(1);
	text.LoadPNG("images/test.png", window->getRenderer(), 0);

	SDL_Rect b;
	b.x = 200;
	b.y = 200;
	b.w = 200;
	b.h = 200;

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		quit = in->updateInput();


		//Render
		SDL_SetRenderDrawColor(window->getRenderer(), 0x01, 0xF0, 0xEE, 0xFF);
		SDL_RenderClear(window->getRenderer());

		SDL_QueryTexture(text.getTexture(0), NULL, NULL, &b.x, &b.y);
		SDL_RenderCopy(window->getRenderer(), text.getTexture(0), NULL, &b);

		SDL_RenderPresent(window->getRenderer());
		
	}


	return 0;
}