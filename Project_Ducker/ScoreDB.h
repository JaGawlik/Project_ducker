#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <regex>

#include "Score.h"

class ScoreDB
{
	std::vector<Score> scoreVector;

	void loadDB();
	void saveDB();

public:

	ScoreDB();
	~ScoreDB();

	//void checkDB();

	std::string checkName(std::string);
	std::string checkPoints(std::string);

	void addScore(Score);
	
	const std::vector<Score> getVector() const;
};

