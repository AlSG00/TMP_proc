#include <fstream>
#include "Documentary.h"

using namespace std;

void Out(Documentary& d, ofstream& ofst)
{
	ofst << ", Release Year = " << d.mYear;
}