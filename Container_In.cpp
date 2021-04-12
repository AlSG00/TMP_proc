#include <fstream>
#include "Container.h"
#include <iostream>

using namespace std;

Movie* In(ifstream& ifdt);

// Ввод содержимого контейнера из указанного потока
void In(Container& c, ifstream& ifst) 
{
    while (!ifst.eof()) 
    {
        if ((c.cont[c.len] = In(ifst)) != 0) 
        { 
            c.len++;      
        }
    }
}