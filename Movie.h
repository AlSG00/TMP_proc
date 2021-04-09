#pragma once
#include "Type.h";
#include "Cartoon.h"
#include "Fiction.h"

struct Movie
{
	type mKey;
	char mName[50];
	union { // ���������� ���������
		Cartoon c;
		Fiction f;
	};
};