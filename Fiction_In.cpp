#include <fstream>
#include <string>
#include "Fiction.h"

using namespace std;

void InFiction(Fiction &f, ifstream& ifst)
{
	string Line; //��������� ������� �� ������ ������������
	getline(ifst, Line); //������ ��������� � Line
	if (Line.length() < 50) { //�������� �� ������������ - ���� ����� Line < 50
		strcpy_s(f.mDirector, 50, Line.c_str());
	}
	else {
		Line.resize(49);
		strcpy_s(f.mDirector, 50, Line.c_str());
	}
	Line.clear();
}