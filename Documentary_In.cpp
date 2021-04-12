#include <fstream>
#include <string>
#include "Documentary.h"

using namespace std;

void InDocumentary(Documentary& d, std::ifstream& ifst)
{
	int Line;
	ifst >> Line;

	if (ifst.fail())
	{
		return;
	}
	else
	{
		d.mYear = Line;
	}
	//ifst >> d.mYear;
}
