#include "parser.h"

void readObjectFromStream(FILE* stream, unsigned long long limit){
    
}

int64 readFixed64(FILE* stream){
    int64 buf;
    fread(&buf, 1, 8, stream);
    return buf;
}