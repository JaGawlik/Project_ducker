#include "Score.h"

Score::Score(std::string nam, int poin)
{
	this->name = nam;
	this->points = poin;
}


std::ostream& operator<<(std::ostream& output, const Score& record)
{
	output << record.name << "/" << record.points << std::endl;
	return output;
}
