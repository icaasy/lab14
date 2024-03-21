#include "libs/data_structures/vector/vector.h"
#include <stdio.h>
#include <assert.h>


void test_vector_content() {
    vector v = createVector(0);
    assert(v.data == NULL);

    v = createVector(1);
    assert(v.capacity == 1);

    reserve(&v, 2);
    assert(v.capacity == 2);

    v.size = 1;
    clear(&v);
    assert(v.size == 0);
    assert(v.data != NULL);

    reserve(&v, 4);
    assert(v.capacity == 4);

    v.size = 2;
    shrinkToFit(&v);
    assert(v.capacity == 2);

    deleteVector(&v);
    assert(v.data == NULL);
}


void test_pushBack_emptyVector() {
    vector v = createVector(0);
    assert(v.capacity == 0);

    pushBack(&v, 1);
    assert(v.capacity == 1);
}


void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.capacity == 2);

    pushBack(&v, 3);

    assert(v.capacity == 4);
    pushBack(&v, 4);
    pushBack(&v, 5);

    assert(v.capacity == 8);
}


void test_popBack_nonEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_vector_memory() {
    vector v = createVector(3);

    pushBack(&v, 1);
    assert(*front(&v) == 1
           && *back(&v) == 1
           && *atVector(&v, 0) == 1
    );

    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(
            getVectorValue(&v, 0) == 1
            && getVectorValue(&v, 1) == 2
            && getVectorValue(&v, 2) == 3
    );

    *back(&v) = 1000;
    *front(&v) = 7;
    *atVector(&v, 1) = 993;
    assert(
            getVectorValue(&v, 0) == 7
            && getVectorValue(&v, 1) == 993
            && getVectorValue(&v, 2) == 1000
    );
}

void test_vector(){
    test_vector_content();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_nonEmptyVector();
    test_vector_memory();
}


int main(){
    test_vector();

    return 0;
}