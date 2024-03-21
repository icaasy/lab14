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




void exceptIndexErrorV(vectorVoid v, const size_t index){
    if (index >= v.size){
        fprintf(stderr, "Index Error");
        exit(1);
    }
}


void exceptEmptyVectorV(vectorVoid v) {
    if (v.size == 0) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
}