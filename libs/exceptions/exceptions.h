#ifndef INC_EXCEPTIONS_H
#define INC_EXCEPTIONS_H

#include "data_structures/vector/vector.h"

// ошибка нехватки памяти
void exceptBadAlloc(vector v);

// ошибка ненайденного элемента
void exceptIndexError(vector v, const size_t index);

// ошибка - вектор пустой
void exceptEmptyVector(vector v);

#endif