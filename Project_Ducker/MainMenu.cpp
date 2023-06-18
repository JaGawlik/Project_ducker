#include "MainMenu.h"

const bool MainMenu::running()
{
	return this->window->isOpen();
}

MainMenu::MainMenu()
{
	this->initFont();
	this->menuMngr();
	this->initBackground();
	this->initHover();
	this->hoverText = false;
}

MainMenu::~MainMenu()
{

}



void MainMenu::initFont()
{
	std::ifstream fstrem("Config/window.init");

	sf::VideoMode resolution(800.f, 600.f);

	/*if (fstrem.is_open())
	{
		fstrem >> resolution.width >> resolution.height;
	}

	fstrem.close();*/

	//this->resolution = sf::VideoMode(800.f, 600.f);
	this->window = new sf::RenderWindow(resolution, "Menu", sf::Style::Close | sf::Style::Titlebar);

	if (!this->menuFont.loadFromFile("Fonts/8-bit Arcade In.ttf"))
	{
		std::cout << "Nie zaladowano fontu";
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


	sf::Text optionsText("Option", menuFont, 50);
	optionsText.setPosition(300.f, 300.f);
	this->menuVector.push_back(optionsText);


	sf::Text exitText("Exit", menuFont, 50);
	exitText.setPosition(300.f, 350.f);
	this->menuVector.push_back(exitText);

	sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
	sf::Vector2f mousePos2f = this->window->mapPixelToCoords(mousePos);

	//Hover animation
	{
		if (playText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(playText.getGlobalBounds().left, playText.getGlobalBounds().top - 50.f);
		}

		if (scText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(scText.getGlobalBounds().left, scText.getGlobalBounds().top - 50.f);
		}

		if (optionsText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(optionsText.getGlobalBounds().left, optionsText.getGlobalBounds().top - 50.f);
		}

		if (exitText.getGlobalBounds().contains(mousePos2f))
		{
			this->hoverText = true;
			this->hoverSprite.setPosition(exitText.getGlobalBounds().left, exitText.getGlobalBounds().top - 50.f);
		}
	}

	while (this->window->pollEvent(this->choice))
	{
		if (this->choice.type == sf::Event::Closed || this->choice.key.code == sf::Keyboard::Escape)
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
					//Game game;
					//Game game;

					/*SFML TIME
					while (game.running())
					{
						game.update();
						game.render();
					}*/
				}

				else if (scText.getGlobalBounds().contains(mousePos2f))
				{
					std::cout << "Wybrano scoreboard";
				}

				else if (optionsText.getGlobalBounds().contains(mousePos2f))
				{
					std::cout << "Wybrano opcje";
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
	//this->hoverSprite.setPosition(400.f, 400.f);
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

void MainMenu::hoverEffect()
{

}

void MainMenu::update()
{
	this->updateHover();
	this->menuMngr();
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
	
	//this->window->draw(this->hoverSprite);

	this->window->display();
}


