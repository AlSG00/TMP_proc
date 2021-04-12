#include "Container.h"
#include <fstream>

using namespace std;

void Out(Movie &mv, ofstream& ofst);

void MultiMethod(Container& c, ofstream& ofst)
{
	ofst << endl << "Multimethod." << endl;
	if (&c != nullptr)
	{
		for (int i = 0; i < c.len - 1; i ++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				switch (c.cont[i]->mKey)
				{
				case type::CARTOON:
					switch (c.cont[j]->mKey)
					{
					case type::CARTOON:
						ofst << "CARTOON and CARTOON." << endl;
						break;
					case type::FICTION:
						ofst << "CARTOON and FICTION." << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				case type::FICTION:
					switch (c.cont[j]->mKey)
					{
					case type::CARTOON:
						ofst << "FICTION and CARTOON." << endl;
						break;
					case type::FICTION:
						ofst << "FICTION and FICTION." << endl;
						break;
					default:
						ofst << "Unknown type" << endl;
					}
					break;
				default:
					ofst << "Unknown type" << endl;
				}
				Out(*(c.cont[i]), ofst);
				Out(*(c.cont[j]), ofst);
				ofst << endl;
			}
		}
	}
	else
	{
		ofst << "Container is empty!" << endl;
	}
}