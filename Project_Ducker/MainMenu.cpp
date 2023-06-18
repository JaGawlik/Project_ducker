#include "MainMenu.h"

const bool MainMenu::running()
{
	return this->window->isOpen();
}

MainMenu::MainMenu()
{
	this->initFont();
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
	//this->hoverSprite.setScale(-1.f, 1);
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
	sf::Text playText("Play", menuFont, 50);
	playText.setPosition(300.f, 200.f);


	sf::Text scText("Scoreboard", menuFont, 50);
	scText.setPosition(300.f, 250.f);


	sf::Text optionsText("Option", menuFont, 50);
	optionsText.setPosition(300.f, 300.f);


	sf::Text exitText("Exit", menuFont, 50);
	exitText.setPosition(300.f, 350.f);


	this->window->draw(playText);
	this->window->draw(scText);
	this->window->draw(optionsText);
	this->window->draw(exitText);

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
				sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
				sf::Vector2f mousePos2f = this->window->mapPixelToCoords(mousePos);

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

void MainMenu::hoverEffect()
{

}

void MainMenu::update()
{
	this->updateHover();
}

void MainMenu::render()
{
	this->window->clear();

	this->window->draw(this->backgroundSprite);
	
	this->showMenu();
	
	//this->window->draw(this->hoverSprite);

	this->window->display();
}


