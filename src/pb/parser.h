#ifndef PB_PARSER_H
#define PB_PARSER_H

#include<stdio.h>
#include "../typedefs.h"

/**
 * Reads an object from stream
 * @param stream The stream to read from
 * @param limit Maximum number of bytes to read
 */
void readObjectFromStream(FILE* stream, uint64 limit);

/**
 * Reads a 64-bit number from the stream
 * @param stream The stream to read from
 */
uint64 readFixed64(FILE* stream);

/**
 * Reads a 32-bit number from the stream
 * @param stream The stream to read from
 */
uint32 readFixed32(FILE* stream);

/**
 * Reads a varint from the stream and returns as int64
 * @param stream The stream to read from
 * @param read_bytes An output parameter, set to the number of bytes read from stream
 */
uint64 readVarint(FILE* stream, uint64* read_bytes);

#endif