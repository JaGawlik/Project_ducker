#include "Game.h"

Game::Game(sf::RenderWindow * win)
{
	this->videoMode = sf::Vector2f(win->getSize());

	this->window = win;
	
	this->initVariables();
	this->initCursor();
	this->initBackground();
	this->initText();
	this->initTargets();
	this->initSummary();
}

Game::~Game()
{
	delete this->window;
	delete this->target;
}

void Game::initVariables()
{
	this->mouseHeld = false;
	this->timeIsOver = false;
	this->clear = false;
	this->deleteLetter = false;
	this->pointsForHit = 3;
	this->gameTime = 1;
	this->counter = 0;
}

void Game::initCursor()
{
	if (!this->crosshairTexture.loadFromFile("Textures/crosshair01.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::CROSSHAIR";
	}

	else
	{
		if (this->crosshair.loadFromPixels(crosshairTexture.getPixelsPtr(), crosshairTexture.getSize(), { 50 , 50 }))
		{
			window->setMouseCursor(crosshair);
		}
	}
}

void Game::initBackground()
{
	if(!this->backgroundTexture.loadFromFile("Textures/background.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::BACKGORUND\n";
	}

	else
	{
		this->background.setTexture(this->backgroundTexture);
	}
}

void Game::initText()
{
	if (!this->gameFont.loadFromFile("Fonts/8-bit Arcade In.ttf"))
	{
		std::cout << "ERROR::FONT NOT LOADED::TEXT FONT\n";
	}

	this->pointText.setFont(this->gameFont);
	this->pointText.setCharacterSize(50);
	this->pointText.setPosition(8.f, 0);
	this->pointText.setOutlineColor(sf::Color::Black);
	this->pointText.setOutlineThickness(0.8f);

	this->timerText.setFont(this->gameFont);
	this->timerText.setCharacterSize(45);
	this->timerText.setPosition(this->videoMode.x - 150.f, 5.f);
	this->timerText.setOutlineColor(sf::Color::Black);
	this->timerText.setOutlineThickness(0.8f);

	this->summaryText.setFont(this->gameFont);
	this->summaryText.setOutlineColor(sf::Color::Black);
	this->summaryText.setOutlineThickness(0.8f);
}

void Game::initTargets()
{
	this->targetSpawnTimer = 15.f;
	this->targetLastSpawn = 0;
	this->maxTargets = 8;
	this->points = 0;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}

			//Keyboard coding
			if (this->ssKeyboardWord.str().length() < 5)
			{
				if (this->event.key.code == sf::Keyboard::A)
				{
					this->nickVector.push_back("a");
					ssKeyboardWord << "a";
					break;
				}

				if (this->event.key.code == sf::Keyboard::B)
				{
					this->nickVector.push_back("b");
					ssKeyboardWord << "b";
					break;
				}

				if (this->event.key.code == sf::Keyboard::C)
				{
					this->nickVector.push_back("c");
					ssKeyboardWord << "c";
					break;
				}

				if (this->event.key.code == sf::Keyboard::D)
				{
					this->nickVector.push_back("d");
					ssKeyboardWord << "d";
					break;
				}

				if (this->event.key.code == sf::Keyboard::E)
				{
					this->nickVector.push_back("e");
					ssKeyboardWord << "e";
					break;
				}

				if (this->event.key.code == sf::Keyboard::F)
				{
					this->nickVector.push_back("f");
					ssKeyboardWord << "f";
					break;
				}

				if (this->event.key.code == sf::Keyboard::G)
				{
					this->nickVector.push_back("g");
					ssKeyboardWord << "g";
					break;
				}

				if (this->event.key.code == sf::Keyboard::H)
				{
					this->nickVector.push_back("h");
					ssKeyboardWord << "h";
					break;
				}

				if (this->event.key.code == sf::Keyboard::I)
				{
					this->nickVector.push_back("i");
					ssKeyboardWord << "i";
					break;
				}

				if (this->event.key.code == sf::Keyboard::J)
				{
					this->nickVector.push_back("j");
					ssKeyboardWord << "j";
					break;
				}

				if (this->event.key.code == sf::Keyboard::K)
				{
					this->nickVector.push_back("k");
					ssKeyboardWord << "k";
					break;
				}

				if (this->event.key.code == sf::Keyboard::L)
				{
					this->nickVector.push_back("l");
					ssKeyboardWord << "l";
					break;
				}

				if (this->event.key.code == sf::Keyboard::M)
				{
					this->nickVector.push_back("m");
					ssKeyboardWord << "m";
					break;
				}

				if (this->event.key.code == sf::Keyboard::N)
				{
					this->nickVector.push_back("n");
					ssKeyboardWord << "n";
					break;
				}

				if (this->event.key.code == sf::Keyboard::O)
				{
					this->nickVector.push_back("o");
					ssKeyboardWord << "o";
					break;
				}

				if (this->event.key.code == sf::Keyboard::P)
				{
					this->nickVector.push_back("p");
					ssKeyboardWord << "p";
					break;
				}

				if (this->event.key.code == sf::Keyboard::Q)
				{
					this->nickVector.push_back("q");
					ssKeyboardWord << "q";
					break;
				}

				if (this->event.key.code == sf::Keyboard::R)
				{
					this->nickVector.push_back("r");
					ssKeyboardWord << "r";
					break;
				}

				if (this->event.key.code == sf::Keyboard::S)
				{
					this->nickVector.push_back("s");
					ssKeyboardWord << "s";
					break;
				}

				if (this->event.key.code == sf::Keyboard::T)
				{
					this->nickVector.push_back("t");
					ssKeyboardWord << "t";
					break;
				}

				if (this->event.key.code == sf::Keyboard::U)
				{
					this->nickVector.push_back("u");
					ssKeyboardWord << "u";
					break;
				}

				if (this->event.key.code == sf::Keyboard::V)
				{
					this->nickVector.push_back("v");
					ssKeyboardWord << "v";
					break;
				}

				if (this->event.key.code == sf::Keyboard::W)
				{
					this->nickVector.push_back("w");
					ssKeyboardWord << "w";
					break;
				}

				if (this->event.key.code == sf::Keyboard::X)
				{
					this->nickVector.push_back("x");
					ssKeyboardWord << "x";
					break;
				}

				if (this->event.key.code == sf::Keyboard::Y)
				{
					this->nickVector.push_back("y");
					ssKeyboardWord << "y";
					break;
				}

				if (this->event.key.code == sf::Keyboard::Z)
				{
					this->nickVector.push_back("z");
					ssKeyboardWord << "z";
					break;
				}

			}

				if (this->event.key.code == sf::Keyboard::Backspace)
				{
					if(this->ssKeyboardWord.str().length() == 0)
					{
						break;
					}

					std::string pop;
					pop = ssKeyboardWord.str();
					pop.pop_back();

					ssKeyboardWord.str("");

					ssKeyboardWord << pop;

					break;
				}

				if (this->event.key.code == sf::Keyboard::Enter)
				{
					//zapis wyniku i nicku do pliku records
				}
		}
	}
}

void Game::updateMousePos()
{
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePos2f = this->window->mapPixelToCoords(this->mousePos);
	//std::cout << mousePos.x << " " << mousePos.y << std::endl;
}

void Game::deleteTargets()
{
	for (int i = 0; i < this->targets.size(); i++)
	{
		this->targets[i]->update();

		//Delete target at edge of the screen
		if (this->targets[i]->Side())
		{
			if ((this->targets[i]->getPosition().x - this->targets[i]->getBounds().width) > this->window->getSize().x)
			{
				delete this->targets.at(i);
				this->targets.erase(this->targets.begin() + i);
			}
		}

		else if (!this->targets[i]->Side())
		{
			if (this->targets[i]->getPosition().x < (0.f - this->targets[i]->getBounds().width))
			{
				delete this->targets.at(i);
				this->targets.erase(this->targets.begin() + i);
			}
		}


		//Dlete target after mouse click	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!this->mouseHeld)
			{
				this->mouseHeld = true;
				
				bool deleted = false;

				for (int i = 0; i < this->targets.size() && !deleted; i++)
				{
					if (this->targets[i]->getBounds().contains(this->mousePos2f))
					{
						deleted = true;
						
						this->onHitVector.push_back(new OnHitAnimation(this->videoMode ,sf::Vector2f(this->targets[i]->getBounds().left + this->targets[i]->getBounds().width /2.f, this->targets[i]->getBounds().top + this->targets[i]->getBounds().height / 2.f)));
						
						delete this->targets.at(i);
																		
						this->targets.erase(this->targets.begin() + i);
					
						this->points += pointsForHit;
					}

				}
			}
		}

		else
		{
			this->mouseHeld = false;
		}		
	}
}

void Game::updateTimer()
{
	if (this->counter < 30)
	{
		this->counter++;
	}

	else
	{
		this->counter = 0;
		this->gameTime--;
	}

	if (gameTime < 0)
	{
		this->timeIsOver = true;
		this->maxTargets = 0;
		this->pointsForHit = 0;
	}

	std::stringstream ss;
	
	ss << "Time " << this->gameTime;

	this->timerText.setString(ss.str());

}

void Game::renderTime(sf::RenderTarget& target)
{
	target.draw(this->timerText);
}

void Game::updateTargets()
{
	if (this->maxTargets > this->targets.size())
	{
		if (this->targetLastSpawn >= this->targetSpawnTimer)
		{
			this->targetLastSpawn = 0.f;

			targets.push_back(new Target(videoMode));
		}

		else
		{
			this->targetLastSpawn += 1.f;
		}
	}
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points " << this->points;
	
	this->pointText.setString(ss.str());
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->pointText);

	if (this->timeIsOver)
	{
		target.draw(this->summaryText);
	}
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePos();
	
	this->updateText();

	this->updateTimer();

	this->updateTargets();

	this->updateOnHit();

	this->deleteTargets();

	if (this->timeIsOver)
	{
		this->updateGameSummary();
	}
}

void Game::render()
{
	this->window->clear();

	if(!this->timeIsOver)
	{
		this->window->draw(this->background);

		for (auto* t : this->targets)
		{
			t->renderTarget(this->window);
		}

		/*this->rendetOnHit(*this->window);*/

		this->renderText(*this->window);

		this->renderTime(*this->window);

		for (auto* i : this->onHitVector)
		{
			i->renderOnHitAnim(*this->window);
		}
	}


	else
	{
		this->window->draw(this->backgroundSummarySprite);

		this->renderText(*this->window);
	}

	this->window->display();

	//std::cout << this->onHitVector.size() << "\n";
	//std::cout << this->targets.size() << "\n";

}

bool Game::gameOver()
{
	return false;
}


void Game::updateOnHit()
{
	for (int i = 0; i < this->onHitVector.size(); i++)
	{
		if (this->onHitVector[i]->getBounds().top + this->onHitVector[i]->getBounds().height >= 0.f)
		{
			this->onHitVector[i]->move(sf::Vector2f(0.f, -10.f));
			this->onHitVector[i]->updateAnimation();
		}

		else
		{
			delete this->onHitVector.at(i);
			this->onHitVector.erase(this->onHitVector.begin() + i);
			break;
		}
	}	
}

void Game::initSummary()
{
	if (!this->backgroundSummaryTexture.loadFromFile("Textures/summaryBackground.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::SUMMARY BACKGORUND\n";
	}

	this->backgroundSummarySprite.setTexture(this->backgroundSummaryTexture);
}

void Game::updateGameSummary()
{
	this->pointText.setPosition(300.f, 250.f);
	this->pointText.setCharacterSize(60);

	this->signIn();
}

void Game::signIn()
{
	this->summaryText.setCharacterSize(60);
	
	if (this->nickVector.size() != 0 && this->clear == false)
	{
		this->ssKeyboardWord.str("");

		this->nickVector.clear();

		this->clear = true;
	}

	else
	{
		this->clear = true;
		
		this->summaryText.setString(ssKeyboardWord.str());	
	}

	this->summaryText.setPosition(((this->window->getSize().x) - (ssKeyboardWord.str().length() * 30.f)) / 2, 400.f);
}

