#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <sstream>
#include <chrono>
#include <fstream>

#include "Target.h"
#include "OnHitAnimation.h"

#include <filesystem>

#include <iostream>



class Game
{
	//sf::VideoMode videoMode;
	sf::Vector2f videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	sf::Sprite background;
	sf::Texture backgroundTexture;

	//Summary
	
	sf::Sprite backgroundSummarySprite;
	sf::Texture backgroundSummaryTexture;

	std::stringstream ssKeyboardWord;
	std::string keyboardWord;
	sf::Text summaryText;
	bool clear;
	bool deleteLetter;
	

	//Targets
	unsigned int points;
	unsigned int pointsForHit;
	int typeTarget;
	float targetSpawnTimer;
	float targetLastSpawn;
	int maxTargets;
	bool mouseHeld;

	sf::Vector2i mousePos;
	sf::Vector2f mousePos2f;

	std::vector <Target*> targets;
	Target* target;

	sf::Text pointText;
	sf::Font gameFont;
	std::vector <std::string> nickVector;

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
	
	void initVariables();
	void initBackground();
	void initText();

public:

	//Constructors
	Game(sf::RenderWindow *);
	~Game();

	//Functions 
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

	bool gameOver();

	void updateOnHit();


	void initSummary();
	void updateGameSummary();

	void signIn();

	void update();
	void render();
};

