#include "parser.h"
#include<stdio.h>
#include<string.h>

#define MAX_VARINT_LENGTH 10

Object* readObjectFromStream(byte* stream, uint64 limit){
    Object* object = newObject();

    byte* stream_end = stream + limit;

    while(stream < stream_end){
        // Read the field descriptor
        uint64 field_read_bytes;
        uint64 field_desc = readVarint(stream, &field_read_bytes);
        stream += field_read_bytes;

        unsigned char type = field_desc & 7;

        void* value = NULL;
        Property* prop = newProperty(field_desc >> 3);
        addPropertyToObject(object, prop);

        switch(type){
            case 0:
                value = getMemory(sizeof(uint64));
                *(uint64*)value = readVarint(stream, &field_read_bytes);
                stream += field_read_bytes;
                setPropertyValue(prop, value, 8, true);
                break;
            case 1:
                value = readFixed64(stream);
                stream += 8;
                setPropertyValue(prop, value, 8, true);
                break;
            case 2: {
                    // Save pointer to the byte string without copying
                    // This may be done later
                    uint64 size = readVarint(stream, &field_read_bytes);
                    stream += field_read_bytes;
                    setPropertyValue(prop, stream, size, false);
                    stream += size;
                }
                break;
            case 5:
                value = readFixed32(stream);
                stream += 4;
                setPropertyValue(prop, value, 4, true);
                break;
            default:
                printf("Unknown message type: %hhu.\n", type);
        }
    }

    return object;
}

uint64* readFixed64(byte* stream){
    uint64* buf = (uint64*)getMemory(sizeof(uint64));
    memcpy(buf, stream, 8);
    return buf;
}

uint32* readFixed32(byte* stream){
    uint32* buf = (uint32*)getMemory(sizeof(uint32));
    memcpy(buf, stream, 4);
    return buf;
}

uint64 readVarint(byte* stream, uint64* read_bytes){
    *read_bytes = 0;

    // Create a 10-bit buffer of zeros for the raw varint
    byte buf[MAX_VARINT_LENGTH];
    for(int i = 0; i < MAX_VARINT_LENGTH; i++) buf[i] = 0;

    // Read the raw varint
    for(int i = 0; i < MAX_VARINT_LENGTH; i++){
        buf[i] = stream[i];
        (*read_bytes)++;
        if((buf[i] & 0x80) == 0) break;
    }

    // Convert the raw representation to standard int
    // Start with the most significant byte
    uint64 num = 0;
    for(int i = MAX_VARINT_LENGTH-1; i >= 0; i--){
        // First, strip the "marker bit"
        byte byte = buf[i] & 0x7f;

        // Then move the bits 7 to the left and insert new
        num <<= 7;
        num |= byte;
    }

    return num;
}

void readBlock(byte* stream, void* buffer, uint64 limit){
    memcpy(buffer, stream, limit);
}