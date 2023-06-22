#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>

#include <fstream>
#include <string>
#include <iostream>

#include "ScoreDB.h"

class Leaderboard
{
	sf::RenderWindow* window;
	sf::Event event;

	//Text
	sf::Text leaderboardText;
	sf::Font leaderboardFont;

	//Background
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	std::vector <sf::Text> leadersVector;

public:

	Leaderboard(sf::RenderWindow *);
	~Leaderboard();

	//Font
	void initFont();

	//Background
	void initBackground();

	//Actions
	void action();
	void showLeaders();

	//DB
	void showDB();

	//Menu
	bool comeback();
	bool backToMenu;

	//Update/Render
	void update();
	void render();

};

