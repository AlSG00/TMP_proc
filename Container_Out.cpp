#include <fstream>
#include "Container.h"

using namespace std;

// ��������� ��������� ������� �������
void Out(Movie& s, ofstream& ofst);

// ����� ����������� ���������� � ��������� �����
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
	ofst << "Only Cartoon movies." << endl;
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
};