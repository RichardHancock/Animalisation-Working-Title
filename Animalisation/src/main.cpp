#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//Constants
const int WIN_POS_X = 100;
const int WIN_POS_Y = 100;
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

//Globals
SDL_Window *window;
SDL_Renderer *renderer;

//Function Prototypes
int init();
int main();
void cleanup();


int init()
{
	int status = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { status = -1; }

	if (TTF_Init() < 0)
	{
		status = -1;
		std::cout << "SDL_ttf init failed: " << TTF_GetError << std::endl;
	}

	window = SDL_CreateWindow("Animalisation",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!window || !renderer) { status = -1; }

	if (status == -1)
	{
		std::cout << "Error occurred in init: " << SDL_GetError() << std::endl;
	}
	return status;
}

void cleanup()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char **argv)
{
	if (init() == -1)
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
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);


		SDL_RenderPresent(renderer);
		
	}

	cleanup();

	return 0;
}