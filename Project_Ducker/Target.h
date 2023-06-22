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

	//Init
	void initTexture();
	void initSprite();
	void initAnimation();

	//Values
	float speed;
	int typeTarget;
	float targetSpawnTimer;
	float targetLastSpawn;
	int maxTargets;
	bool LeftRight; //ture from left side
	
	bool Side();

public:

	//Target(sf::VideoMode);
	Target(sf::Vector2f);
	~Target();

	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	
	//Spawning
	void spawnTarget();
	
	//Animation
	void updateMovement();
	void updateAnimation();

	//Update/Render
	void update();
	void renderTarget(sf::RenderTarget* tar);


};

