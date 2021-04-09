#include <fstream>
#include <string>
#include "Cartoon.h"

using namespace std;

void InCartoon(Cartoon &c, std::ifstream& ifst)
{
	string Data;
	int mType;
	ifst >> mType;
	if (mType == 0)
	{
		c.mType = Cartoon::DRAWN;
	}
	else if (mType == 1)
	{
		c.mType = Cartoon::RAGDOLL;
	}
	else if (mType == 2)
	{
		c.mType = Cartoon::PLASTICINE;
	}
}
