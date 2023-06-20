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

	//Font
	sf::Font menuFont;
	sf::Text menuOptions;
	std::vector <sf::Text> menuVector;


	//Background
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	//HoverEffects
	sf::Clock animationHoverTimer;
	sf::Sprite hoverSprite;
	sf::Texture hoverTexture;
	sf::IntRect currentHoverFrame;

	unsigned int deci; //0 menu, 1 game, 2 scoreboard, 3 options

	bool hoverText;
	
public:

	MainMenu(sf::RenderWindow *);
	~MainMenu();

	const bool running();

	void initWindow();
	void menuMngr();

	void initBackground();

	void initHover();
	void updateHover();

	void showMenu();

	void createScoreFile();

	//void renderGame();

	int decision();
	
	void update();
	void render();

};

