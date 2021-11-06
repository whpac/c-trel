#ifndef FILES_READER_H
#define FILES_READER_H

#include "../typedefs.h"

/**
 * Reads the whole file into memory and returns a pointer to the first byte
 * @param path Path to the file
 * @param size An output parameter, set to the number of bytes in file
 */
void* readFile(const char* path, uint64* size);

#endif