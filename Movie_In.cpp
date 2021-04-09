#include <fstream>
#include <string>
#include "Movie.h"

using namespace std;

// ��������� ��������� ������� �������
void InCartoon(Cartoon &c, ifstream& ifst);
void InFiction(Fiction &f, ifstream& ifst);

// ���� ���������� ���������� ������ �� �����
Movie* In(ifstream& ifst)
{
	Movie* mv;
	string Line; //��������� ������� �� ������ ������������
	int key;
	ifst >> key;
	switch (key)
	{
	case 1:
		mv = new Movie;
		mv->mKey = type::CARTOON;
		getline(ifst, Line); //������ ��������� � Line
		getline(ifst, Line);
		if (Line.length() < 50) { //�������� �� ������������ - ���� ����� Line < 50
			strcpy_s(mv->mName, 50, Line.c_str());
			InCartoon(mv->c, ifst);
			return mv;
		}
		else {
			Line.resize(49);
			strcpy_s(mv->mName, 50, Line.c_str());
			InCartoon(mv->c, ifst);
			return mv;
		}
	case 2:
		mv = new Movie;
		mv->mKey = type::FICTION;
		getline(ifst, Line); //������ ��������� � Line
		getline(ifst, Line);
		if (Line.length() < 50) { //�������� �� ������������ - ���� ����� Line < 50
			strcpy_s(mv->mName, 50, Line.c_str());
			InFiction(mv->f, ifst);
			return mv;
		}
		else {
			Line.resize(49);
			strcpy_s(mv->mName, 50, Line.c_str());
			InFiction(mv->f, ifst);
			return mv;
		}
	default:
		char Junk[50]; //��� ������
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		return 0;
	}
	Line.clear();
}