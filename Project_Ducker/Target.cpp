#include "Target.h"

bool Target::Side()
{
	return LeftRight;
}

Target::Target(sf::VideoMode vMode)
{
	this->posXY.x = vMode.width;
	this->posXY.y = vMode.height;

	this->initTexture();
	this->initSprite();
	this->initAnimation();
	
	this->spawnTarget();
	this->speed = 1.f;
}

Target::~Target()
{
	
}

sf::FloatRect Target::getBounds()
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Target::getPosition()
{
	return this->sprite.getPosition();
}


void Target::initTexture()
{
	if (!this->texture.loadFromFile("Textures/BirdSpriteBig.png"))
	{
		std::cout << "Nie zaladowano tekstury \n";
	}
}

void Target::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 160, 160, 160);
	this->sprite.setTextureRect(this->currentFrame);
}

void Target::initAnimation()
{
	this->animationTimer.restart();
}

void Target::renderTarget(sf::RenderTarget* target)
{
	//std::cout << "pozycja x: " << this->target.getPosition().x << " pozycja y: " << this->target.getPosition().y << "\n";
	target->draw(this->sprite);
}

void Target::updateMovement()
{	
	if (LeftRight == true)
	{
		this->sprite.setScale(-0.5f, 0.5f);
		this->sprite.move(5.f * this->speed, 0.f);
	}

	else
	{
		this->sprite.setScale(0.5f, 0.5f);
		this->sprite.move(-5.f * this->speed, 0.f);
	}
}


void Target::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asMilliseconds()>= 200.f * this->speed)
	{
		this->currentFrame.left += 160.f;
		if (this->currentFrame.left >= 1120.f)
		{
			this->currentFrame.left = 0;
		}
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Target::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Target::spawnTarget()
{
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, this->posXY.y - sprite.getGlobalBounds().height);

	int strona = dist(gen);

	float zmienna = dist(gen);

	if (strona % 2)
	{
		LeftRight = true;
		this->sprite.setPosition(0.f - this->sprite.getGlobalBounds().width, zmienna);
	}

	else
	{
		LeftRight = false;
		this->sprite.setPosition(posXY.x, zmienna);
	}
}
 
