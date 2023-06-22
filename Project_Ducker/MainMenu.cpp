#include "MainMenu.h"

const bool MainMenu::running()
{
	return this->window->isOpen();
}


MainMenu::MainMenu(sf::RenderWindow* wind)
{
	this->window = wind;

	this->deci = 0;

	this->initWindow();
	this->menuMngr();
	this->initBackground();
	this->initHover();
	this->hoverText = false;

	this->createScoreFile();
}

MainMenu::~MainMenu()
{

}

void MainMenu::initWindow()
{
	//std::ifstream fstrem("Config/window.init");

	sf::VideoMode resolution(800.f, 600.f);

	if (!this->menuFont.loadFromFile("Fonts/8-bit Arcade In.ttf"))
	{
		std::cout << "ERROR::FONT NOT LOADED::MENU FONT\n";
	}
}

void MainMenu::menuMngr()
{
	sf::Text playText("Play", menuFont, 50);
	playText.setPosition(300.f, 200.f);
	this->menuVector.push_back(playText);


	sf::Text scText("Scoreboard", menuFont, 50);
	scText.setPosition(300.f, 250.f);
	this->menuVector.push_back(scText);


	sf::Text exitText("Exit", menuFont, 50);
	exitText.setPosition(300.f, 300.f);
	this->menuVector.push_back(exitText);

	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
	sf::Vector2f mousePos2f = this->window->mapPixelToCoords(mousePos);

	//Text hover effect
	{
		if (playText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(playText.getGlobalBounds().left - 10.f, playText.getGlobalBounds().top - 50.f);
		}

		if (scText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(scText.getGlobalBounds().left - 10.f, scText.getGlobalBounds().top - 50.f);
		}

		if (exitText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(exitText.getGlobalBounds().left - 10.f, exitText.getGlobalBounds().top - 50.f);
		}
	}

	while (this->window->pollEvent(this->choice))
	{
		if (this->choice.type == sf::Event::Closed)
		{
			this->window->close();
		}

		if (this->choice.type == sf::Event::MouseButtonPressed)
		{
			if (this->choice.mouseButton.button == sf::Mouse::Left)
			{
				if (playText.getGlobalBounds().contains(mousePos2f))
				{
					std::cout << "Wybrano play";
					
					this->deci = 1;
				}

				else if (scText.getGlobalBounds().contains(mousePos2f))
				{
					std::cout << "Wybrano scoreboard";
					this->deci = 2;
				}

				else if (exitText.getGlobalBounds().contains(mousePos2f))
				{
					std::cout << "Wybrano exit";
					this->window->close();
				}
			}
		}
	}
}

void MainMenu::initBackground()
{
	if (!this->backgroundTexture.loadFromFile("Textures/myBackground.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::BACKGROUND";
	}

	this->backgroundSprite.setTexture(this->backgroundTexture);
}

void MainMenu::initHover()
{
	if (!this->hoverTexture.loadFromFile("Textures/BirdSpriteBig.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::HOVER TEXTURE";
	}

	this->hoverSprite.setTexture(this->hoverTexture);
	this->hoverSprite.setScale(-0.5f, 0.5f);
	this->currentHoverFrame = sf::IntRect(0, 320, 160, 160);
	this->hoverSprite.setTextureRect(this->currentHoverFrame);
}

void MainMenu::updateHover()
{
	
	if (this->animationHoverTimer.getElapsedTime().asMilliseconds() >= 1500.f)
	{
		this->currentHoverFrame.left += 160.f;
		if (this->currentHoverFrame.left >= 320.f)
		{
			this->currentHoverFrame.left = 0;
		}
		this->animationHoverTimer.restart();
		this->hoverSprite.setTextureRect(this->currentHoverFrame);
	}
}

void MainMenu::showMenu()
{
	for (int i = 0; i < this->menuVector.size(); i++)
	{
		this->window->draw(this->menuVector[i]);
	}
}

void MainMenu::createScoreFile()
{
	if (!std::filesystem::exists("Scoreboard"))
	{
		std::filesystem::create_directory("Scoreboard/");

		std::filesystem::path source = "Template/recordsTemplate.txt";
		std::filesystem::path destination = "Scoreboard/records.txt";

		std::filesystem::copy(source, destination, std::filesystem::copy_options::overwrite_existing);
	}
}

int MainMenu::decision()
{
	return this->deci;
}

void MainMenu::setDecision(int dec)
{
	this->deci = dec;
}

void MainMenu::update()
{
	this->updateHover();
	this->menuMngr();
	this->decision();
}

void MainMenu::render()
{
	this->window->clear();

	this->window->draw(this->backgroundSprite);

	this->showMenu();

	if (this->hoverText)
	{
		this->window->draw(this->hoverSprite);
	}

	this->window->display();
}


