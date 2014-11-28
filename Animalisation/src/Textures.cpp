#include "Textures.h"

Textures::Textures(int numberOfTextures)
{
	// resize vector
	m_texturesArray.resize(numberOfTextures);
}
Textures::~Textures()
{
	// free memory
	m_texturesArray.clear();
}
void Textures::LoadPNG(std::string filename, SDL_Renderer* rend, int index)
{
	// make sure there is a file name
	if (filename.empty())
	{
		std::cout << "NO FILENAME ENTERED!\n";
	}
	// load the image
	SDL_Surface* texture = IMG_Load(filename.c_str());

	if (!texture)
	{
		std::cout << "Failed to load image\n";
	}
	//else
	{
		// create a texture from the surface
		m_texturesArray[index] = SDL_CreateTextureFromSurface(rend, texture);
	
		// free texutre
		SDL_FreeSurface(texture);
	}
}
