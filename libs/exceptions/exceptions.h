#ifndef INC_EXCEPTIONS_H
#define INC_EXCEPTIONS_H

#include "data_structures/vector/vector.h"

// ошибка нехватки памяти
void exceptBadAlloc(vector v);

// ошибка ненайденного элемента
void exceptIndexError(vector v);

#endif