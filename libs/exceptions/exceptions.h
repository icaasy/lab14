#ifndef INC_EXCEPTIONS_H
#define INC_EXCEPTIONS_H

#include "data_structures/vector/vector.h"
#include "data_structures/vector/vectorVoid.h"

// ошибка нехватки памяти
void exceptBadAlloc();

// ошибка - вектор пустой
void exceptEmptyVector();

// ошибка ненайденного элемента
void exceptIndexError();

// ошибка нехватки памяти
void exceptBadAllocV(vectorVoid v);

// ошибка ненайденного элемента
void exceptIndexErrorV(vectorVoid v, const size_t index);

// ошибка - вектор пустой
void exceptEmptyVectorV(vectorVoid v);

#endif