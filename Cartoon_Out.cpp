#include <fstream>
#include "Cartoon.h"

using namespace std;

void Out(Cartoon& c, ofstream& ofst)
{
	ofst << ", Creation type = ";
	if (c.mType == 0)
	{
		ofst << "Drawned" << endl;
	}
	else if (c.mType == 1)
	{
		ofst << "Ragdoll" << endl;
	}
	else if (c.mType == 2)
	{
		ofst << "Plasticine" << endl;
	}
}