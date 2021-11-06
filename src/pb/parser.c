#include "parser.h"

#define MAX_VARINT_LENGTH 10

void readObjectFromStream(FILE* stream, uint64 limit){
    
}

uint64 readFixed64(FILE* stream){
    uint64 buf;
    fread(&buf, 1, 8, stream);
    return buf;
}

uint64 readVarint(FILE* stream){
    // Create a 10-bit buffer of zeros for the raw varint
    unsigned char buf[MAX_VARINT_LENGTH];
    for(int i = 0; i < MAX_VARINT_LENGTH; i++) buf[i] = 0;

    // Read the raw varint
    for(int i = 0; i < MAX_VARINT_LENGTH; i++){
        fread(&buf[i], 1, 1, stream);
        if((buf[i] & 0x80) == 0) break;
    }

    // Convert the raw representation to standard int
    // Start with the most significant byte
    uint64 num = 0;
    for(int i = MAX_VARINT_LENGTH-1; i >= 0; i--){
        // First, strip the "marker bit"
        unsigned char byte = buf[i] & 0x7f;

        // Then move the bits 7 to the left and insert new
        num <<= 7;
        num |= byte;
    }

    return num;
}