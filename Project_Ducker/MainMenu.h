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

	bool hoverText;

	
public:

	MainMenu();
	~MainMenu();

	const bool running();

	void initFont();
	void menuMngr();

	void initBackground();

	void initHover();
	void updateHover();

	void showMenu();

	void hoverEffect();
	
	void update();
	void render();

};

