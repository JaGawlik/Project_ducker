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
	

public:

	General();
	~General();

	const bool running();

	//Init
	void initGeneralWindow();
	void reInit();

	//Update/Render
	void update();
	void render();
};

