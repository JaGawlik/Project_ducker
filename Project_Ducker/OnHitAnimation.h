#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class OnHitAnimation
{

	sf::Texture onHitTexture;
	sf::Sprite onHitSprite;
	sf::Clock onHitClock;
	sf::IntRect onHitFrame;

	sf::Vector2f position;

public:
	OnHitAnimation(sf::Vector2f);
	~OnHitAnimation();

	void updateOnHit();

	void onHitAnimation(sf::Vector2f);
	void initOnHit();
	void renderOnHitAnim(sf::RenderTarget& target);
};

