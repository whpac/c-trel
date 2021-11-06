#ifndef PB_PARSER_H
#define PB_PARSER_H

#include<stdio.h>
#include "data/int64.h"

typedef unsigned long long uint64;

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

/**
 * Reads a varint from the stream and returns as int64
 * @param stream The stream to read from
 */
uint64 readVarint(FILE* stream);

#endif