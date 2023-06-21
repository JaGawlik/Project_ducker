#include "General.h"

General::General()
{
	this->initGeneralWindow();
	this->menu = new MainMenu(this->window);
	this->game = new Game(this->window);
	this->leaderboard = new Leaderboard(this->window);
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
}

void General::reInit()
{
	delete this->game;
	this->game = new Game(this->window);
}

void General::update()
{
	if (menu->decision() == 0)
	{
		this->menu->update();
	}

	if (menu->decision() == 1)
	{
		if (!this->game->comeback())
		{
			this->game->update();
		}

		else
		{
			this->menu->setDecision(0);
			this->game->backToMenu = false;
			this->reInit();
		}
	}

	if (menu->decision() == 2)
	{
		if (!this->leaderboard->comeback())
		{
			this->leaderboard->update();
		}

		else
		{
			this->menu->setDecision(0);
			this->leaderboard->backToMenu = false;
		}
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

	if (menu->decision() == 2)
	{
		this->leaderboard->render();
	}


}
