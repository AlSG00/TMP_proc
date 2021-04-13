#include <fstream>
#include "Documentary.h"

using namespace std;

void Out(Documentary& d, ofstream& ofst)
{
	if (1900 > d.mYear || 2030 < d.mYear)		//ограничение на вводимую дату
	{
		ofst << ", and there is ERROR in Year ";
	}
	else
	{
		ofst << ", Release Year = " << d.mYear;
	}
}