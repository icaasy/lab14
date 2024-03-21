#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

// возвращает пустой вектор, в который можно вставить n элементов
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserveV(vectorVoid *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clearV(vectorVoid *v);

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *v);

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v);



#endif