#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Game.h"

class MainMenu
{
	//sf::VideoMode resolution;

	sf::RenderWindow* window;
	sf::Event choice;

	sf::Font menuFont;
	sf::Text menuOptions[4];



	
public:

	MainMenu();
	~MainMenu();

	const bool running();

	void init();
	void show();
	void update();
	void render();

};

