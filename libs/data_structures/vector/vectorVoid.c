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



bool isEmptyV(vectorVoid *v){
    return v->size == 0;
}


bool isFullV(vectorVoid *v){
    return v->size == v->capacity;
}


void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    exceptIndexErrorV(*v, index);
    char *source = (char *)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}



void setVectorValueV(vectorVoid *v, size_t index, void *source){
    exceptIndexErrorV(*v, index);
    char *dst = (char *)v->data + index * v->baseTypeSize;
    memcpy(dst, source, v->baseTypeSize);
}


void popBackV(vectorVoid *v){
    exceptEmptyVectorV(*v);
    v->size--;
}


void pushBackV(vectorVoid *v, void *source){
    if (!v->capacity){
        reserveV(v, 1);
    } else if (v->size == v->capacity){
        reserveV(v, v->capacity * 2);
    }

    char *dst = (char *)v->data + v->size++ * v->baseTypeSize;
    memcpy(dst, source, v->baseTypeSize);
}