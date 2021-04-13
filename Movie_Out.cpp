#include <fstream>
#include "Movie.h"

using namespace std;

void Out(Cartoon& c, ofstream& ofst);
void Out(Fiction& f, ofstream& ofst);
void Out(Documentary& d, ofstream& ofst);
int VowelsCount(Movie& mv);

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
	case type::DOCUMENTARY:
		ofst << "It is DOCUMENTARY movie called " << mv.mName;
		Out(mv.d, ofst);
		break;
	default:
		ofst << "Incorrect movie!" << endl;
	}
	ofst << ", Made in : " << mv.mCountry;
	ofst << ", Count of vowels = " << VowelsCount(mv) << endl;
};

int VowelsCount(Movie& mv) {
	int vowel = 0;
	int i = 0;
	while (mv.mName[i] != '\0')
	{
		switch (mv.mName[i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			 vowel++;
		}
		i++;
	}
	return vowel;
};

bool Compare(Movie* first, Movie* second)
{
	return VowelsCount(*first) > VowelsCount(*second);
};