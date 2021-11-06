#ifndef PB_PARSER_H
#define PB_PARSER_H

#include<stdio.h>
#include "../typedefs.h"
#include "object.h"

/**
 * Reads an object from stream
 * @param stream The stream to read from
 * @param limit Maximum number of bytes to read
 */
Object* readObjectFromStream(FILE* stream, uint64 limit);

/**
 * Reads a 64-bit number from the stream
 * @param stream The stream to read from
 */
uint64* readFixed64(FILE* stream);

/**
 * Reads a 32-bit number from the stream
 * @param stream The stream to read from
 */
uint32* readFixed32(FILE* stream);

/**
 * Reads a varint from the stream and returns as int64
 * @param stream The stream to read from
 * @param read_bytes An output parameter, set to the number of bytes read from stream
 */
uint64 readVarint(FILE* stream, uint64* read_bytes);

/**
 * Reads a sequence of bytes and saves it into the buffer.
 * Returns a number of bytes that were actually read.
 * @param stream The stream to read from
 * @param buffer A pointer to the destination memory area
 * @param limit How many bytes to read
 */
uint64 readBlock(FILE* stream, void* buffer, uint64 limit);

#endif