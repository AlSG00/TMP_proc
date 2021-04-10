#include <fstream>
#include "Container.h"

using namespace std;

// Сигнатуры требуемых внешних функций
void Out(Movie& s, ofstream& ofst);

// Вывод содержимого контейнера в указанный поток
void Out(Container& c, ofstream& ofst)
{
    ofst << "Container contains " << c.len << " elements." << endl;
    for (int i = 0; i < c.len; i++)
    {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

void OutCartoon(Container& c, ofstream& ofst)
{
	ofst << endl << "Only Cartoon movies." << endl;
	for (int i = 0; i < c.len; i++)
	{
		ofst << i << ": ";
		if (c.cont[i]->mKey == type::CARTOON)
		{
			Out(*(c.cont[i]), ofst);
		}
		else
		{
			ofst << endl;

		}
	}
}

bool Compare(Movie* first, Movie* second);

// Сортировка содержимого контейнера
void Sort(Container& c)
{
	for (int i = 0; i < c.len - 1; i++)
	{
		for (int j = i + 1; j < c.len; j++)
		{
			if (Compare(c.cont[i], c.cont[j])) 
			{
				Movie* tmp = c.cont[i];
				c.cont[i] = c.cont[j];
				c.cont[j] = tmp;
			}
		}
	}
};