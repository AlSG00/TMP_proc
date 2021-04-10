#include <fstream>
#include "Fiction.h"

using namespace std;

void Out(Fiction& f, ofstream& ofst) 
{
	ofst << ", Director's name = " << f.mDirector ;
}