#pragma once

#include "Game.h"
#include "MainMenu.h"
#include "Leaderboard.h"

class General
{
	sf::RenderWindow* window;
	sf::VideoMode resolution;

	MainMenu* menu;
	Game* game;
	Leaderboard* leaderboard;
	
	std::filesystem::path path;

	int decisss;

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

