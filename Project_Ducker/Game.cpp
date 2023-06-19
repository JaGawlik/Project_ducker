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
	this->endGame = false;
	this->mouseHeld = false;
	this->timeIsOver = false;
	this->gameTime = 2;
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

	this->gameText.setFont(this->gameFont);
	this->gameText.setCharacterSize(50);
	this->gameText.setPosition(8.f, 0);
	this->gameText.setOutlineColor(sf::Color::Black);
	this->gameText.setOutlineThickness(0.8f);

	this->timerText.setFont(this->gameFont);
	this->timerText.setCharacterSize(45);
	this->timerText.setPosition(this->videoMode.x - 150.f, 5.f);
	this->timerText.setOutlineColor(sf::Color::Black);
	this->timerText.setOutlineThickness(0.8f);
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
				this->window->close();
			break;
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
					
						this->points += 3;
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
	
	this->gameText.setString(ss.str());
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->gameText);
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
	this->gameText.setPosition(300.f, 250.f);
	this->gameText.setCharacterSize(60);
}

void Game::signIn()
{

}






