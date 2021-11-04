#ifndef PB_DATA_INT64_H
#define PB_DATA_INT64_H

#define INT64_SIZE 8

typedef struct int64 int64;

/**
 * Represents an 8-byte number.
 * 
 * The byte0 is the least significant one
 * and the byte7 is the most significant.
 * 
 * The order of fields complies with little-endian norm.
 */
struct int64 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
    unsigned char byte5;
    unsigned char byte6;
    unsigned char byte7;
};

#endif