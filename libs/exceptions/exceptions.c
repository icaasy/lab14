#include "exceptions.h"


void exceptBadAlloc(vector v){
    if (!v.data){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}