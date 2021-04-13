#include <fstream>
#include <string>
#include "Movie.h"

#include <iostream>

using namespace std;

// Сигнатуры требуемых внешних функций
void InCartoon(Cartoon &c, ifstream& ifst);
void InFiction(Fiction &f, ifstream& ifst);
void InDocumentary(Documentary& d, ifstream& ifst);

Movie* In(ifstream& ifst)
{
	Movie* mv;
	string Line; //Временное решение на случай переполнения
	int key;
	ifst >> key;
	
	if (ifst.fail())
	{
		ifst.clear();
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}
	else
	{
		switch (key)
		{
		case 1:
			mv = new Movie;
			mv->mKey = type::CARTOON;

			getline(ifst, Line);
			getline(ifst, Line);
			Line.resize(49);

			strcpy_s(mv->mName, 50, Line.c_str());
			InCartoon(mv->c, ifst);

			Line.clear();
			ifst >> Line;
			Line.resize(49);
			strcpy_s(mv->mCountry, 50, Line.c_str());
			Line.clear();
			return mv;
		case 2:
			mv = new Movie;
			mv->mKey = type::FICTION;

			getline(ifst, Line);
			getline(ifst, Line);
			Line.resize(49);
			strcpy_s(mv->mName, 50, Line.c_str());
			InFiction(mv->f, ifst);

			Line.clear();
			ifst >> Line;
			Line.resize(49);
			strcpy_s(mv->mCountry, 50, Line.c_str());
			Line.clear();
			return mv;
		case 3:
			mv = new Movie;
			mv->mKey = type::DOCUMENTARY;
			getline(ifst, Line);
			getline(ifst, Line);
			Line.resize(49);
			strcpy_s(mv->mName, 50, Line.c_str());
			InDocumentary(mv->d, ifst);

			Line.clear();
			ifst >> Line;
			Line.resize(49);
			strcpy_s(mv->mCountry, 50, Line.c_str());
			Line.clear();
			return mv;
		default:
			char Junk[50]; //для мусора
			ifst.getline(Junk, 50);
			ifst.getline(Junk, 50);
			ifst.getline(Junk, 50);
			return 0;
		}
		Line.clear();
	}
}