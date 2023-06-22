#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <sstream>
#include <chrono>
#include <fstream>

#include "Target.h"
#include "OnHitAnimation.h"
#include "Score.h"
#include "ScoreDB.h"

#include <filesystem>
#include <iostream>



class Game
{
	//Decision
	unsigned int decision;

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

	//Audio
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::SoundBuffer bufferPoint;
	sf::Sound soundPoint;
	bool loop;

	

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

	//Text
	sf::Text pointText;
	sf::Font gameFont;

	//SignIn
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

	std::vector<Score> scoreVector;

public:

	//Constructors
	Game(sf::RenderWindow*);
	~Game();

	//Functions 
	
	//Basic
	const bool running() const;
	
	void pollEvents();
	void updateMousePos();

	//Text
	void updateText();
	void renderText(sf::RenderTarget & target);

	void updateTimer();
	void renderTime(sf::RenderTarget & target);

	//Cursor
	void initCursor();

	//Targets
	void initTargets();
	void deleteTargets();
	void updateTargets();

	//OnHitAnimation
	void updateOnHit();

	//Audio
	void initAudio();


	//Summary
	void initSummary();
	void updateGameSummary();
	void signIn();
	

	//Render/Update
	void update();
	void render();

	

	bool comeback();
	bool backToMenu;
};

