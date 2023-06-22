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

	std::string checkName(std::string);
	std::string checkPoints(std::string);

	//AddToDB
	void addScore(Score);
	
	const std::vector<Score> getVector() const;
};

