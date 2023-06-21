#pragma once

#include <sstream>

class Score
{
public:

	std::string name;
	int points;

	Score(std::string, int);

	friend std::ostream& operator << (std::ostream& output, const Score& hiScore);

	bool operator < (const Score& object) const
	{
		return (this->points < object.points);
	}

	bool operator > (const Score& object) const
	{
		return (this->points > object.points);
	}
};
