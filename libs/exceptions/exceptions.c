#include "exceptions.h"


void exceptBadAlloc(vector v){
    if (!v.data){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}


void exceptEmptyVector(vector v){
    if (v.size == 0){
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
}

void exceptIndexError(vector v, const size_t index) {
    if (index >= v.size) {
        fprintf(stderr, "Index Error");
        exit(1);
    }
}
