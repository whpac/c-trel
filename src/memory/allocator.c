#include "allocator.h"
#include<malloc.h>
#include<stdio.h>

void* getMemory(unsigned int size){
    void* ptr = malloc(size);
    // printf("[Alloc]: %u bytes at addr %llu\n", size, (unsigned long long)ptr);
    return ptr;
}

void freeMemory(void* mem){
    // printf("[Dealloc]: at addr %llu\n", (unsigned long long)mem);
    free(mem);
}