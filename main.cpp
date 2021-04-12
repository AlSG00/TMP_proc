#include <iostream>
#include <fstream>
#include "Container.h"

using namespace std;

// Сигнатуры требуемых внешних функций
void Init(Container& c);
void Clear(Container& c);
void In(Container& c, ifstream& ifst);
void Out(Container& c, ofstream& ofst);
void MultiMethod(Container& c, ofstream& ofst);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	Container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled Container. " << endl;
	Out(c, ofst);
	MultiMethod(c, ofst);
	Clear(c);
	ofst << "Empty Container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}