#include "parser.h"

#define MAX_VARINT_LENGTH 10

Object* readObjectFromStream(FILE* stream, uint64 limit){
    uint64 read_bytes = 0;
    Object* object = newObject();

    while(read_bytes < limit && !feof(stream)){
        // Read the field descriptor
        uint64 field_read_bytes;
        uint64 field_desc = readVarint(stream, &field_read_bytes);
        read_bytes += field_read_bytes;

        unsigned char type = field_desc & 7;

        void* value = NULL;
        Property* prop = newProperty(field_desc >> 3);
        addPropertyToObject(object, prop);

        switch(type){
            case 0:
                value = malloc(sizeof(uint64));
                *(uint64*)value = readVarint(stream, &field_read_bytes);
                read_bytes += field_read_bytes;
                setPropertyValue(prop, value, 8);
                break;
            case 1:
                value = readFixed64(stream);
                read_bytes += 8;
                setPropertyValue(prop, value, 8);
                break;
            case 2:
                break;
            case 5:
                value = readFixed32(stream);
                read_bytes += 4;
                setPropertyValue(prop, value, 4);
                break;
            default:
                printf("Unknown message type: %hhu.\n", type);
        }
        printf("[%lld]: %lld\n", field_desc >> 3, *(uint64*)value);
    }

    return object;
}

uint64* readFixed64(FILE* stream){
    uint64* buf = (uint64*)malloc(sizeof(uint64));
    fread(buf, 1, 8, stream);
    return buf;
}

uint32* readFixed32(FILE* stream){
    uint32* buf = (uint32*)malloc(sizeof(uint32));
    fread(buf, 1, 4, stream);
    return buf;
}

uint64 readVarint(FILE* stream, uint64* read_bytes){
    *read_bytes = 0;

    // Create a 10-bit buffer of zeros for the raw varint
    unsigned char buf[MAX_VARINT_LENGTH];
    for(int i = 0; i < MAX_VARINT_LENGTH; i++) buf[i] = 0;

    // Read the raw varint
    for(int i = 0; i < MAX_VARINT_LENGTH; i++){
        fread(&buf[i], 1, 1, stream);
        (*read_bytes)++;
        if((buf[i] & 0x80) == 0) break;
        if(feof(stream)) break;
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