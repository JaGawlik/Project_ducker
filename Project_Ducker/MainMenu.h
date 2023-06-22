#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
//#include <fstream>
#include <sstream>

#include "Game.h"

class MainMenu
{
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
	bool hoverText;

	unsigned int deci; //0 menu, 1 game, 2 scoreboard, 3 options
	
public:

	MainMenu(sf::RenderWindow *);
	~MainMenu();

	const bool running();
	
	//Menu
	void initWindow();
	void menuMngr();
	void showMenu();
	int decision();

	//Background
	void initBackground();

	//Hover
	void initHover();
	void updateHover();

	//Score file
	void createScoreFile();

	//Leaderboard
	void setDecision(int);
	
	//Update/Render
	void update();
	void render();

};

