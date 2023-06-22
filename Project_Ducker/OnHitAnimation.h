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

	sf::Clock animationTimer;
	sf::IntRect currentFrame;

	void center();
	bool getEndScreen();

public:

	OnHitAnimation(sf::Vector2f, sf::Vector2f);
	~OnHitAnimation();

	//Init
	void initSprite();
	void initOnHit();

	//Update
	void updateAnimation();
	void move(sf::Vector2f);

	//Update/Render
	void updateOnHit(std::vector <OnHitAnimation*>);
	void renderOnHitAnim(sf::RenderTarget& target);

	const sf::FloatRect getBounds() const;
};

