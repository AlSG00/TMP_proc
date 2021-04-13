#pragma once
#include "Movie.h"

struct Container
{
    enum { max_len = 100 }; // максимальная длина
    int len;                // текущая длина
    Movie* cont[max_len];
};
