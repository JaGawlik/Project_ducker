#pragma once

#include "Game.h"
#include "MainMenu.h"

class General
{
	sf::RenderWindow* window;
	sf::VideoMode resolution;

	MainMenu* menu;
	Game* game;

	/*bool menuMode;
	bool gameMode;
	bool scoreboardMode;
	bool optionsMode;*/

public:

	General();
	~General();

	const bool running();

	void initGeneralWindow();

	void update();
	void render();
};

