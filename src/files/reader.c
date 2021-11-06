#include "reader.h"
#include<stdio.h>
#include "../memory/allocator.h"

void* readFile(const char* path, uint64* size){
    FILE* f = fopen(path, "rb");
    if(f == NULL){
        *size = 0;
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    *size = ftell(f);

    fseek(f, 0, SEEK_SET);
    void* contents = getMemory(*size);

    fread(contents, 1, *size, f);
    fclose(f);

    return contents;
}