#include <fstream>
#include "Cartoon.h"

using namespace std;

void Out(Cartoon& c, ofstream& ofst)
{
	if (!(c.mType == 0 || c.mType == 1 || c.mType == 2))
	{
		ofst << ", and there is ERROR in Type ";
	}
	else
	{
		ofst << ", Creation type = ";
		if (c.mType == 0)
		{
			ofst << "Drawned";
		}
		else if (c.mType == 1)
		{
			ofst << "Ragdoll";
		}
		else if (c.mType == 2)
		{
			ofst << "Plasticine";
		}
	}
}