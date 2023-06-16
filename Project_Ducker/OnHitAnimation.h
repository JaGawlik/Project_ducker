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

	bool endScreen;
	float limit;

	void center();

public:
	OnHitAnimation(sf::VideoMode,sf::Vector2f);
	~OnHitAnimation();

	void updateOnHit(std::vector <OnHitAnimation*>);

	void initOnHit();
	void renderOnHitAnim(sf::RenderTarget& target);

	bool getEndScreen();

	void move(sf::Vector2f);

	const sf::FloatRect getBounds() const;



};

