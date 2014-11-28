#include "Window.h"
#include <iostream>

Window::Window(char* title, int winWidth, int winHeight)
{
	//Init
	int status = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { status = -1; }

	if (TTF_Init() < 0)
	{
		status = -1;
		std::cout << "SDL_ttf init failed: " << TTF_GetError << std::endl;
	}

	window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!window || !renderer) { status = -1; }

	if (status == -1)
	{
		std::cout << "Error occurred in init: " << SDL_GetError() << std::endl;
		delete this;
	}
	
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* Window::getRenderer() { return renderer; }

SDL_Window* Window::getWindow() { return window; }