#include <iostream>
#include "Window.h"
#include "Textures.h"
#include "Terrain.h"

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

	// create world
	terrain ter(10, 10);
	// load textures
	Textures text(4);
	text.LoadPNG("images/grass.png", window->getRenderer(), 0);
	text.LoadPNG("images/town.png", window->getRenderer(), 1);
	text.LoadPNG("images/hill.png", window->getRenderer(), 2);
	text.LoadPNG("images/water.png", window->getRenderer(), 3);

	// bind textures
	for (int i = 0; i < ter.sizeOf(); ++i)
	{
		switch (ter.getTileType(i))
		{
		case tGrass:	ter.bindTileTexture(text.getTexture(tGrass), i);
			break;
		case tHills:	ter.bindTileTexture(text.getTexture(tHills), i);
			break;
		case tTown:		ter.bindTileTexture(text.getTexture(tTown), i);
			break;
		case tWater:	ter.bindTileTexture(text.getTexture(tWater), i);
			break;
		}			
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
		SDL_SetRenderDrawColor(window->getRenderer(), 0x01, 0x01, 0x01, 0xFF);
		SDL_RenderClear(window->getRenderer());

		// draw
		ter.draw();
		// actual draw
		for (int i = 0; i < ter.sizeOf(); ++i)
		{
			SDL_Rect b = ter.getRect(i);
      b.w = 150;
			b.h = 150;
			SDL_RenderCopy(window->getRenderer(), text.getTexture(ter.getTileType(i)), NULL, &b);
		}

		SDL_RenderPresent(window->getRenderer());
		
	}


	return 0;
}