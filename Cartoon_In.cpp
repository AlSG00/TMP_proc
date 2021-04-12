#include <fstream>
#include <string>
#include "Cartoon.h"

using namespace std;

void InCartoon(Cartoon &c, std::ifstream& ifst)
{
	int Line;
	ifst >> Line;
	if (ifst.fail())
	{
		//mType = NULL;
		return;
	}
	else
	{
		if (Line == 0)
		{
			c.mType = Cartoon::DRAWN;
		}
		else if (Line == 1)
		{
			c.mType = Cartoon::RAGDOLL;
		}
		else if (Line == 2)
		{
			c.mType = Cartoon::PLASTICINE;
		}
	}

	//string Data;
	//int mType;
	//ifst >> mType;
	//if (mType == 0)
	//{
	//	c.mType = Cartoon::DRAWN;
	//}
	//else if (mType == 1)
	//{
	//	c.mType = Cartoon::RAGDOLL;
	//}
	//else if (mType == 2)
	//{
	//	c.mType = Cartoon::PLASTICINE;
	//}
}
