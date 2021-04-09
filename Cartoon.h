#pragma once
#include "Type.h"

using namespace std;

struct Cartoon
{
	enum creationType
	{
		DRAWN,
		RAGDOLL,
		PLASTICINE
	};
	creationType mType;
};