#include <fstream>
#include <string>
#include "Fiction.h"

using namespace std;

void InFiction(Fiction &f, ifstream& ifst)
{
	string Line;
	getline(ifst, Line); //Ñòðîêà çàíîñèòñÿ â Line
	Line.resize(49);
	strcpy_s(f.mDirector, 50, Line.c_str());

	//string Line; //Временное решение на случай переполнения
	//getline(ifst, Line); //Строка заносится в Line
	//if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 50
	//	strcpy_s(f.mDirector, 50, Line.c_str());
	//}
	//else {
	//	Line.resize(49);
	//	strcpy_s(f.mDirector, 50, Line.c_str());
	//}
	Line.clear();
}