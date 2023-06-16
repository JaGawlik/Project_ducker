#include "OnHitAnimation.h"

OnHitAnimation::OnHitAnimation(sf::VideoMode vMode ,sf::Vector2f pos)
{
	limit = vMode.height;
	this->position = pos;
	this->initOnHit();
}

OnHitAnimation::~OnHitAnimation()
{

}

void OnHitAnimation::updateOnHit(std::vector <OnHitAnimation*> onHitVector)
{

	if ((this->onHitSprite.getGlobalBounds().top - this->onHitSprite.getGlobalBounds().height) >= 0.f)
	{
		this->onHitSprite.move(0, -10.f);
		this->endScreen = false;
	}

	else
	{
		this->endScreen = true;
	}

}

void OnHitAnimation::initOnHit()
{
	/*sf::Texture onHitTexture;
	sf::Sprite onHitSprite;
	sf::Clock onHitClock;
	sf::IntRect onHitFrame;*/
	if (!this->onHitTexture.loadFromFile("Textures/1.png"))
	{
		std::cout << "ERROR::TEXTURE NOT LOADED::ON HIT TEXTURE\n";
	}
	this->onHitSprite.setTexture(this->onHitTexture);

	this->onHitSprite.setPosition(this->position);
	this->center();
}


void OnHitAnimation::renderOnHitAnim(sf::RenderTarget& target)
{
	target.draw(this->onHitSprite);
}

bool OnHitAnimation::getEndScreen()
{
	return this->endScreen;
}

void OnHitAnimation::move(sf::Vector2f move)
{
	this->onHitSprite.move(move.x, move.y);
}

const sf::FloatRect OnHitAnimation::getBounds() const
{

	return this->onHitSprite.getGlobalBounds();
}

void OnHitAnimation::center()
{
	this->onHitSprite.setPosition(this->onHitSprite.getGlobalBounds().left - (this->onHitSprite.getGlobalBounds().width * (1.f / 2.f)), this->onHitSprite.getGlobalBounds().top - (this->onHitSprite.getGlobalBounds().height * (1.f / 2.f)));
}

