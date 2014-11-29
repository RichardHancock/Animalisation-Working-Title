#include "menu.h"

Menu::Menu(Window* window)
{
	/*initailse the variables*/
	background->LoadPNG("images/menuBack.png", window->getRenderer(), 0);
	key[0] = new MenuKey("images/playWhite.png", window);
	key[1] = new MenuKey("images/quitWhite.png", window);
	keyH[0] = new MenuKey("images/playBlue.png", window);
	keyH[1] = new MenuKey("images/quitBlue.png", window);
	highlightedKey = 0;
	lastUp = false;
	lastDown = false;
}

Menu::~Menu()
{

}

void Menu::displayMenu(Window* window)
{
	

	//Render
	SDL_SetRenderDrawColor(window->getRenderer(), 0x01, 0xF0, 0xEE, 0xFF);
	SDL_RenderClear(window->getRenderer());

	/*updates the out box*/
	b.x = 0;
	b.y = 0;
	b.w = 640;
	b.h = 480;
	/*send out the background*/
	SDL_RenderCopy(window->getRenderer(), background->getTexture(0), NULL, &b);

	/*updates the out box*/
	b.x = 225;
	b.w = 179;
	b.h = 100;

	/*checks which key is highlighted and makes that output the highlighed key instead. also updates the y outbox*/
	switch (highlightedKey)
	{
	case 0:
		b.y = 100;
		SDL_RenderCopy(window->getRenderer(), keyH[0]->getPic()->getTexture(0), NULL, &b);

		b.y = 200;
		SDL_RenderCopy(window->getRenderer(), key[1]->getPic()->getTexture(0), NULL, &b);
		break;

	case 1:
		b.y = 100;
		SDL_RenderCopy(window->getRenderer(), key[0]->getPic()->getTexture(0), NULL, &b);
		
		b.y = 200;
		SDL_RenderCopy(window->getRenderer(), keyH[1]->getPic()->getTexture(0), NULL, &b);
		break;

	case 2:
		b.y = 100;
		SDL_RenderCopy(window->getRenderer(), key[0]->getPic()->getTexture(0), NULL, &b);

		b.y = 200;
		SDL_RenderCopy(window->getRenderer(), key[1]->getPic()->getTexture(0), NULL, &b);
		break;
	}

	SDL_RenderPresent(window->getRenderer());
}

bool Menu::updateMenu(bool up, bool down, bool enter)
{
	/*check if thge key can change in the chosen direction and do if possible*/
	if (up != lastUp)
	{
		if (up)
		{
			if (highlightedKey > 0)
			{
				highlightedKey--;
			}
			lastUp = true;
		}
		else
		{
			lastUp = false;
		}
	}

	if (down != lastDown)
	{
		if (down)
		{
			if (highlightedKey < 1)
			{
				highlightedKey++;
			}
			lastDown = true;
		}
		else
		{
			lastDown = false;
		}
	}

	if (enter)
	{
		/*end loop*/
		return false;
	}
	/*still loop*/
	return true;
}

int Menu::getHighlight()
{
	/*return the key number*/
	return highlightedKey;
}