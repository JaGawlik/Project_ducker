#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <thread>

#include <sstream>
#include <chrono>

#include <Windows.h>

#include "Target.h"
#include "OnHitAnimation.h"

#include <iostream>



class Game
{
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	bool endGame;
	sf::Sprite background;
	sf::Texture backgroundTexture;

//	unsigned int gameTime;

	//Targets
	unsigned int points;
	int typeTarget;
	float targetSpawnTimer;
	float targetLastSpawn;
	int maxTargets;
	bool mouseHeld;

	sf::Vector2i mousePos;
	sf::Vector2f mousePos2f;

	//Cele
	std::vector <Target*> targets;
	Target* target;

	sf::Text gameText;
	sf::Font gameFont;

	//Timer
	sf::Clock clock;
	sf::Time countdownTime;
	sf::Text timerText;
	bool timeIsOver;
	unsigned int counter;
	int gameTime;

	//Cursor
	sf::Cursor crosshair;
	sf::Image crosshairTexture;

	//On Hit
	sf::Texture onHitTexture;
	std::vector <OnHitAnimation*> onHitVector;
	
	/*sf::Text onHitText;
	sf::Font onHitFont;*/

	void initVariables();
	void initWindow();
	void initBackground();
	void initText();

	//void createTarget();

	//CELE moze do targeta
	//float targetSpawnTimer;
	//float targetSpawnTimerMax;
	//int maxTargets;


public:

	//Konstruktor
	Game(sf::VideoMode);
	~Game();

	//Metody 
	const bool running() const;
	
	void pollEvents();
	void updateMousePos();

	void updateText();
	void renderText(sf::RenderTarget & target);

	void updateTimer();
	void renderTime(sf::RenderTarget & target);

	void initCursor();


	void initTargets();

	void deleteTargets();

	void updateTargets();

	void update();
	void render();

	bool gameOver();

	void initOnHit();

	//sf::Sprite onHitAnima();

	

	//void onhitAnimation(sf::Vector2f);
	//void rendetOnHit(sf::RenderTarget& target);
	
};

