#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H

#include<stddef.h>

/**
 * Allocates a specified amount of memory
 * @param size Number of bytes to allocate
 */
void* getMemory(unsigned int size);

/**
 * Frees a memory block
 * @param mem Pointer to a memory block to free
 */
void freeMemory(void* mem);

#endif