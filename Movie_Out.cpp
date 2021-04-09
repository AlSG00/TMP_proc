#include <fstream>
#include "Movie.h"

using namespace std;

void Out(Cartoon& c, ofstream& ofst);
void Out(Fiction& f, ofstream& ofst);

void Out(Movie& mv, ofstream& ofst) 
{
	switch (mv.mKey) 
	{
	case type::CARTOON:
		ofst << "It is CARTOON movie called " << mv.mName;
		Out(mv.c, ofst);
		break;
	case type::FICTION:
		ofst << "It is FICTION movie called " << mv.mName;
		Out(mv.f, ofst);
		break;
	default:
		ofst << "Incorrect movie!" << endl;
	}
	ofst << ", Made in : " << mv.mCountry << endl;
};