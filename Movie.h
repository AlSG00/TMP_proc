#pragma once
#include "Type.h";
#include "Cartoon.h"
#include "Fiction.h"
#include "Documentary.h"

struct Movie
{
	type mKey;
	char mCountry[50];
	char mName[50];
	union { // ���������� ���������
		Cartoon c;
		Fiction f;
		Documentary d;
	};
};