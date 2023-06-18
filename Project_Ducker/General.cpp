#include "General.h"

General::General()
{
	this->initGeneralWindow();
	this->menu = new MainMenu(this->window);
	this->game = new Game(this->window);
}

General::~General()
{
	delete this->menu;
	delete this->game;
}

const bool General::running()
{
	return this->window->isOpen();
}

void General::initGeneralWindow()
{
	this->resolution = sf::VideoMode(800.f, 600.f);
	this->window = new sf::RenderWindow(resolution, "Kurka Wodna", sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(30);

	/*this->menuMode = true;
	this->gameMode = false;
	this->scoreboardMode = false;
	this->optionsMode = false;	*/
}

void General::update()
{
	if (menu->decision() == 0)
	{
		this->menu->update();
	}

	if (menu->decision() == 1)
	{
		this->game->update();
	}
}

void General::render()
{
	if (menu->decision() == 0)
	{
		this->menu->render();
	}

	if (menu->decision() == 1)
	{
		this->game->render();
	}


}
