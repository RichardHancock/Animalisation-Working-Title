#pragma once
#include "Window.h"
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <iostream>

/** 
@brief Class that loads and stores Textures 
*/
class Textures
{
public:

	/** 
	@brief Creates the Texture loader

	Initializes internal storage with passed in param
	@param int - The number of textures that will be loaded
	*/
	Textures(int numberOfTextures);
	~Textures();

	/**
	@brief Loads a texture from a PNG (or others I believe)

	Loads a texture from a PNG and stores it internally in the array
	@param std::string - Filepath to image
	@param SDL_Renderer* - Pointer to the renderer
	@param int - Position in the internal vector
	*/
	void LoadPNG(std::string filename, SDL_Renderer* rend, int index);

	/** 
	@brief Returns a the specified SDL_Texture*

	@param int - Position in the internal vector
	@returns SDL_Texture* - The requested texture
	*/
	inline SDL_Texture* getTexture(int index)
	{ return m_texturesArray[index];}

private:
	std::vector<SDL_Texture*> m_texturesArray;
};
