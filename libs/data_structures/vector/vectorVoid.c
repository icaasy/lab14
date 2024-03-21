#include "data_structures/vector/vectorVoid.h"
#include "exceptions/exceptions.h"


vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid new;

    if (n == 0){
        new.data = NULL;
    } else {
        new.data = malloc(n * baseTypeSize);
        exceptBadAllocV(new);
    }

    new.size = 0;
    new.capacity = n;
    new.baseTypeSize = baseTypeSize;

    return new;
}


void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0){
        v->data = NULL;
    } else {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
        exceptBadAllocV(*v);
    }

    v->size = v->size > newCapacity ? newCapacity : v->size;
    v->capacity = newCapacity;
}


void clearV(vectorVoid *v){
    v->size = 0;
}


void shrinkToFitV(vectorVoid *v){
    if (v->capacity > v->size){
        v->data = realloc(v->data, v->baseTypeSize * v->size);
        v->capacity = v->size;
    }
}


void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}