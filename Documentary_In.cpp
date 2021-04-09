#include <fstream>
#include <string>
#include "Documentary.h"

using namespace std;

void InDocumentary(Documentary& d, std::ifstream& ifst)
{
	ifst >> d.mYear;
}
