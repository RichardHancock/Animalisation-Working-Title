#include "menuKey.h"

MenuKey::MenuKey(std::string filename, Window* window)
{
	/*load the image to the texture*/
	key->LoadPNG(filename, window->getRenderer(), 0);
}

MenuKey::~MenuKey()
{
	/*deletes the key*/
	delete key;
}

Textures* MenuKey::getPic()
{
	/*returns the texture*/
	return key;
}