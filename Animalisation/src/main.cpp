#include <iostream>
#include "Window.h"
#include "Textures.h"
#include "inputManager.h"
#include "Terrain.h"
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

	terrain ter(5, 5);

	Textures text(2);
	text.LoadPNG("images/test.png", window->getRenderer(), 0);
	text.LoadPNG("images/HexT.png", window->getRenderer(), 1);

	for (int i = 0; i < ter.sizeOf(); ++i)
	{
		ter.bindTileTexture(text.getTexture(1), i);
	}



	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		quit = in->updateInput();


		//Render
		SDL_SetRenderDrawColor(window->getRenderer(), 0x01, 0xF0, 0xEE, 0xFF);
		SDL_RenderClear(window->getRenderer());

		ter.draw();
		//SDL_QueryTexture(text.getTexture(1), NULL, NULL, &b.x, &b.y);
		for (int i = 0; i < ter.sizeOf(); ++i)
		{
			SDL_Rect b = ter.getRect(i);
      b.w = 150;
			b.h = 150;
			SDL_RenderCopy(window->getRenderer(), text.getTexture(1), NULL, &b);
		}
		

		SDL_RenderPresent(window->getRenderer());
		
	}


	return 0;
}