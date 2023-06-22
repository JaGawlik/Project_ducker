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

//void ScoreDB::checkDB()
//{
//	std::regex nameCheck("[a-zA-Z]{1,5}");
//	std::regex pointsCheck("[0-9]{1,3}");
//
//	std::regex eraseFromName("[0-9]");
//	std::regex eraseFromPoints("[a-zA-Z]");
//
//
//	if (!std::regex_match(scoreboardName, nameCheck) || std::regex_match(regexPoints, pointsCheck))
//	{
//		if (!std::regex_match(scoreboardName, nameCheck))
//		{
//			std::regex_replace(scoreboardName, eraseFromName, "");
//		}
//
//		else if (!std::regex_match(regexPoints, pointsCheck))
//		{
//			std::regex_replace(regexPoints, eraseFromPoints, "");
//		}
//
//		else if (!std::regex_match(scoreboardName, nameCheck) && std::regex_match(regexPoints, pointsCheck))
//		{
//			std::regex_replace(scoreboardName, eraseFromName, "");
//			std::regex_replace(regexPoints, eraseFromPoints, "");
//		}
//	}
//}

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
			std::string regexPoints;
			int scoreboardPoints;

			while (std::getline(part11, part1, '/'))
			{

				switch (nameScore)
				{
				case true:


					scoreboardName = this->checkName(part1);

					nameScore = false;

					break;

				case false:
					

					scoreboardPoints = stoi(this->checkPoints(part1));
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


std::string ScoreDB::checkName(std::string toCheck)
{
	std::smatch match;

	std::regex nameCheck("[a-zA-Z]{1,5}");

	std::regex eraseFromName("[0-9]");

	if (std::regex_search(toCheck, match, nameCheck))
	{
		return match[0];
	}

	else
	{
		return "xxxxx";
	}

}

std::string ScoreDB::checkPoints(std::string toCheck)
{
	std::smatch match;

	std::regex pointsCheck("[0-9]{1,3}");

	std::regex eraseFromPoints("[a-zA-Z]");

	if (std::regex_search(toCheck, match, pointsCheck))
	{
		return match[0];
	}

	else
	{
		return "000";
	}
}

void ScoreDB::addScore(Score sc)
{
	this->scoreVector.push_back(sc);
}

const std::vector<Score> ScoreDB::getVector() const
{
	return this->scoreVector;
}

