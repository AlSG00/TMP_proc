#include "Container.h"
#include "Movie.h"

void Init(Container& c) 
{ 
    c.len = 0; 
}
// Очистка контейнера от элементов
// (освобождение памяти)
void Clear(Container& c) 
{
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}