#include <fstream>
#include <string>
#include "Cartoon.h"

using namespace std;

void InCartoon(Cartoon &c, std::ifstream& ifst)
{
	int Line;
	ifst >> Line;

	//Функция завершается при получении данных неверного формата
	if (ifst.fail())	
	{
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
}
