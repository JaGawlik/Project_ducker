#include "Leaderboard.h"

Leaderboard::Leaderboard(sf::RenderWindow* win)
{
	this->window = win;

	this->initFont();
	this->initBackground();


}

Leaderboard::~Leaderboard()
{

}


void Leaderboard::showLeaders()
{
	ScoreDB db;

	for (int i = 0; i < 5; i++)
	{
		sf::Text text;
		
		text.setFont(this->leaderboardFont);
		text.setCharacterSize(50);
		text.setOutlineThickness(0.8f);
		text.setOutlineColor(sf::Color::Black);

		this->leadersVector.push_back(text);

		std::stringstream ss;
		ss << db.getVector()[i].name << " " << db.getVector()[i].points;
		this->leadersVector[i].setString(ss.str());

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
			this->backToMenu = true;
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

void Leaderboard::showDB()
{
	ScoreDB db;

	for (int i = 0; i < db.getVector().size(); i++)
	{
		db.getVector()[i].name;
	}
}

bool Leaderboard::comeback()
{
	return this->backToMenu;
}
