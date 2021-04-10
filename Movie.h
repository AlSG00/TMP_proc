#pragma once
#include "Type.h";
#include "Cartoon.h"
#include "Fiction.h"
#include "Documentary.h"

struct Movie
{
	type mKey;
	char mName[50];
	char mCountry[50];
	union { // используем включение
		Cartoon c;
		Fiction f;
		Documentary d;
	};
};