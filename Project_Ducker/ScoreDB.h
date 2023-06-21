#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "Score.h"

class ScoreDB
{
	std::vector<Score> scoreVector;

	void loadDB();
	void saveDB();

public:

	ScoreDB();
	~ScoreDB();

	void addScore(Score);
	
	const std::vector<Score> getVector() const;
};

