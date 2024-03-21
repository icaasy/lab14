#include "exceptions.h"


void exceptBadAlloc(vector v){
    if (!v.data){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}


void exceptIndexError(vector v){
    if (v.size == 0){
        fprintf(stderr, "Index Error");
        exit(1);
    }
}