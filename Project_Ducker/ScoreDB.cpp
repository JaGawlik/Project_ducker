#include "ScoreDB.h"

ScoreDB::ScoreDB()
{
	this->scoreVector = {};
	this->loadDB();
}

ScoreDB::~ScoreDB()
{
	this->saveDB();
}

void ScoreDB::loadDB()
{
	std::ifstream file("Scoreboard/records.txt");

	if (file.is_open())
	{
		std::string line;
		std::stringstream ss;

		while (std::getline(file, line))
		{
			std::string part1;
			std::stringstream part11;

			part11 << line;

			bool nameScore = true; // true name // false score

			std::string scoreboardName;
			int scoreboardPoints;

			while (std::getline(part11, part1, '/'))
			{

				switch (nameScore)
				{
				case true:

					scoreboardName = part1;
					nameScore = false;

					break;

				case false:
					scoreboardPoints = stoi(part1);
					nameScore = true;
					break;
				}
			}

			Score sc(scoreboardName, scoreboardPoints);

			this->scoreVector.push_back(sc);

			std::sort(this->scoreVector.begin(), this->scoreVector.end(), std::greater<Score>());
		}

		file.close();
	}

	else
	{
		std::cout << "ERROR::THE SAVE FILE CAN NOT BE OPENED\n";
	}
}

void ScoreDB::saveDB()
{
	std::ofstream file("Scoreboard/records.txt");

	if (!file.is_open())
	{
		std::cout << "ERROR::THE SAVE FILE CAN NOT BE OPENED\n";
	}

	else
	{
		for (auto& sc : this->scoreVector)
		{
			file << sc;
		}
	}

	file.close();
}

void ScoreDB::addScore(Score sc)
{
	this->scoreVector.push_back(sc);
}

const std::vector<Score> ScoreDB::getVector() const
{
	return this->scoreVector;
}

