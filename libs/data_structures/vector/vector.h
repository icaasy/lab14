#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает пустой вектор, в который можно вставить n элементов
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);


//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору
void deleteVector(vector *v);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

// возвращает 'истина' если вектор пустой, иначе - 'ложь'
bool isEmpty(vector *v);

// возвращает 'истина' если вектор полный, иначе - 'ложь'
bool isFull(vector *v);

// возвращает i-ый элемент вектора
int getVectorValue(vector *v, size_t i);

// добавляет в конец вектора число x
void pushBack(vector *v, int x);

// удаляет последний элемент вектора
void popBack(vector *v);

#endif