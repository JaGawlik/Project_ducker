#include "OnHitAnimation.h"

OnHitAnimation::OnHitAnimation(sf::Vector2f pos)
{
	this->position = pos;
	this->initOnHit();
	this->updateOnHit();


}


OnHitAnimation::~OnHitAnimation()
{
}

void OnHitAnimation::updateOnHit()
{
	for (int i = 0; i < 4; i++)
	{
		this->onHitSprite.move(0, 2.f);
	}
}


void OnHitAnimation::onHitAnimation(sf::Vector2f pos)
{
	this->onHitSprite.setPosition(pos);
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
}

void OnHitAnimation::renderOnHitAnim(sf::RenderTarget& target)
{
	target.draw(this->onHitSprite);
}