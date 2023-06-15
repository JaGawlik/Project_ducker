#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <Windows.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <random>

class Target
{
	sf::Sprite sprite;
	sf::Texture texture;

	std::vector <sf::Sprite> targets;
	sf::Vector2f posXY;

	sf::Clock animationTimer;
	sf::IntRect currentFrame;

	void initTexture();
	void initSprite();
	void initAnimation();

	//int points;
	int typeTarget;
	float targetSpawnTimer;
	float targetLastSpawn;
	int maxTargets;
	bool LeftRight; //ture od lewej
	
public:

	//Target(sf::Vector2f);
	Target(sf::VideoMode);
	~Target();

	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	bool Side();
	

	//void initTarget();
	void renderTarget(sf::RenderTarget* tar);
	//void spawnTarget();

	void updateMovement();
	void updateAnimation();

	void update();

	void spawnTarget();

	


	
	//void createTarget();

	//void setTargetPosition();
	//void createTarget();
	//void updateTarget();
};

