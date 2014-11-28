#pragma once
#include "Window.h"
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <iostream>

class Textures
{
public:

	Textures(int numberOfTextures);
	~Textures();

	void LoadPNG(std::string filename, SDL_Renderer* rend, int index);

	inline SDL_Texture* getTexture(int index)
	{ return m_texturesArray[index];}

private:
	std::vector<SDL_Texture*> m_texturesArray;
};
