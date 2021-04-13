#include <iostream>
#include <fstream>
#include "Container.h"

using namespace std;

// Сигнатуры требуемых внешних функций
void Init(Container& c);
void Clear(Container& c);
void In(Container& c, ifstream& ifst);
void Out(Container& c, ofstream& ofst);
void OutCartoon(Container& c, ofstream& ofst);
void Sort(Container& c);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	if (!ifst)
	{
		cout << "No input file!" << endl;
		return 0;
	}
	Container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled Container. " << endl;
	Out(c, ofst);

	ofst << "\n\nSorted container." << endl;
	Sort(c);
	Out(c, ofst);

	OutCartoon(c, ofst);

	Clear(c);
	ofst << "Empty Container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}