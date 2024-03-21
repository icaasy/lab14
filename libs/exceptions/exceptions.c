#include "exceptions.h"


void exceptBadAlloc(){
    fprintf(stderr, "bad alloc");
    exit(1);
}


void exceptEmptyVector(){
    fprintf(stderr, "Vector is empty");
    exit(1);
}


void exceptIndexError(){
    fprintf(stderr, "Index Error");
    exit(1);


}
void exceptBadAllocV(vectorVoid v) {
    if (!v.data) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}