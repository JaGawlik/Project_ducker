#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* win)
{
	this->window = win;

	this->initFont();
	this->initBackground();
	
}

Leaderboard::~Leaderboard()
{
	this->window;
}

void Leaderboard::loadData()
{
	std::ifstream file("Scoreboard/records.txt");

	if (file.is_open())
	{
		std::string line;

		while (std::getline(file, line))
		{

		}

		file.close();
	}
}

void Leaderboard::initFont()
{
	if (!this->leaderboardFont.loadFromFile("Fonts/8-bit Arcade In.ttf"))
	{
		std::cout << "ERROR::FONT NOT LOADED::SCOREBOARD FONT";
	}

	else
	{
		this->leaderboardText.setFont(this->leaderboardFont);
	}
}


void Leaderboard::initBackground()
{
	if (!this->backgroundTexture.loadFromFile("Textures/leaderboard.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::LEADERBOARD TEXTURE";
	}

	else
	{
		this->backgroundSprite.setTexture(this->backgroundTexture);
	}
}

void Leaderboard::action()
{
	while (this->window->pollEvent(event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}

		if (this->event.key.code == sf::Keyboard::Escape)
		{
			//powrot do menu
			
		}
	}
}


void Leaderboard::update()
{
	this->action();
}

void Leaderboard::render()
{
	this->window->clear();

	this->window->draw(this->backgroundSprite);


	this->window->display();
}
