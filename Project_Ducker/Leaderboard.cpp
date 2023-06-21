#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* win)
{
	this->window = win;

	this->initFont();
	this->initBackground();
	this->loadData();
}

Leaderboard::~Leaderboard()
{
	this->window;
}

void Leaderboard::loadData()
{
	std::ifstream file("Scoreboard/records.txt");

	if (!file.is_open())
	{
		std::cout << "ERROR::THE SAVE FILE CAN NOT BE OPENED\n";
	}

	else
	{
		std::string line;

		while (std::getline(file, line))
		{
			std::stringstream ss;
			ss << line;

			this->leaderboardText.setString(ss.str());

			this->leadersVector.push_back(this->leaderboardText);
		}

		file.close();
	}
}

void Leaderboard::showLeaders()
{
	for (int i = 0; i < this->leadersVector.size(); i++)
	{
		this->leadersVector[i].setPosition(((this->window->getSize().x - this->leadersVector[i].getGlobalBounds().width) / 2), (230.f + i * (this->leadersVector[i].getGlobalBounds().height + 25.f)));
		this->window->draw(this->leadersVector[i]);
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
		this->leaderboardText.setCharacterSize(50);
		this->leaderboardText.setOutlineThickness(0.8f);
		this->leaderboardText.setOutlineColor(sf::Color::Black);
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

	this->showLeaders();

	this->window->display();
}
