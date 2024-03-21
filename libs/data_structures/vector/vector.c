#include <data_structures/vector/vector.h>


vector createVector(size_t n){
    vector new;
    new.data = (int *) malloc(n * sizeof(int));
    new.size = 0;
    new.capacity = n;

    if (!new.data){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return new;
}


void reserve(vector *v, size_t newCapacity){
    v->data = (int *)realloc(v->data, sizeof(int) * newCapacity);
    v->size = v->size > newCapacity ? newCapacity : v->size;
    v->capacity = newCapacity;
}


void shrinkToFit(vector *v){
    if (v->capacity > v->size){
        v->data = (int *)realloc(v->data, sizeof(int) * v->size);
        v->capacity = v->size;
    }
}


void deleteVector(vector *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}