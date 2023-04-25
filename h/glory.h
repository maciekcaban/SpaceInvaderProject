#include <string>

class glory
{
public:
	std::string gPlayerName;
	int gScore;

	glory();

	bool operator> (glory&);
};