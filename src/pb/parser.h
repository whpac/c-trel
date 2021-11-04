#ifndef PB_PARSER_H
#define PB_PARSER_H

#include<stdio.h>
#include "data/int64.h"

/**
 * Reads an object from stream
 * @param stream The stream to read from
 * @param limit Maximum number of bytes to read
 */
void readObjectFromStream(FILE* stream, unsigned long long limit);

/**
 * Reads a 64-bit number from the stream
 * @param stream The stream to read from
 */
int64 readFixed64(FILE* stream);

#endif