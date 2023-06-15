#include "MainMenu.h"

const bool MainMenu::running()
{
	return this->window->isOpen();
}

MainMenu::MainMenu()
{
	this->init();
}

MainMenu::~MainMenu()
{
}



void MainMenu::init()
{
	std::ifstream fstrem("Config/window.init");

	sf::VideoMode resolution(800, 600);

	if (fstrem.is_open())
	{
		fstrem >> resolution.width >> resolution.height;
	}

	fstrem.close();

	//this->resolution = sf::VideoMode(800.f, 600.f);
	this->window = new sf::RenderWindow(resolution, "Menu", sf::Style::Close | sf::Style::Titlebar);
	

	if (!this->menuFont.loadFromFile("Fonts/Pacifico.ttf"))
	{
		std::cout << "Nie zaladowano fontu";
	}
}

void MainMenu::show()
{
	sf::Text playText("Play", menuFont, 30);
	playText.setPosition(350.f, 200.f);


	sf::Text scText("Scoreboard", menuFont, 30);
	scText.setPosition(350.f, 250.f);


	sf::Text optionsText("Option", menuFont, 30);
	optionsText.setPosition(350.f, 300.f);


	sf::Text exitText("Exit", menuFont, 30);
	exitText.setPosition(350.f, 350.f);


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
				sf::Vector2f mousePos2f = this->window->mapPixelToCoords(mousePos);;

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

void MainMenu::update()
{
	
}

void MainMenu::render()
{
	this->window->clear();

	this->show();

	this->window->display();
	
}


