#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <filesystem>

#include <fstream>
#include <string>
#include <iostream>

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

	bool back;

public:

	Leaderboard(sf::RenderWindow *);
	~Leaderboard();

	//Data reading
	void loadData();

	//Font
	void initFont();

	//Background
	void initBackground();

	void action();

	void update();
	void render();
};

