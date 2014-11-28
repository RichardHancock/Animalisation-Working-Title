#include <iostream>
#include "Window.h"

//Constants
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

//Globals
Window* window = new Window("Animalisation", WIN_WIDTH, WIN_HEIGHT);

//Function Prototypes
int main();



int main(int argc, char **argv)
{
	if (!window)
	{
		return -1;
	}

	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			//Escape Key
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}


		//Render
		SDL_SetRenderDrawColor(window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(window->getRenderer());


		SDL_RenderPresent(window->getRenderer());
		
	}


	return 0;
}