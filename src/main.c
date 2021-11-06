#include<stdio.h>
#include "typedefs.h"
#include "pb/parser.h"
#include "files/reader.h"

int main(){
    uint64 size;
    void* data = readFile("_sample/test.bin", &size);

    Object* o = readObjectFromStream((byte*)data, 13);
    freeMemory(data);

    Property* p = getObjectFirstProperty(o);
    while(p != NULL){
        uint64* v = (uint64*)getPropertyValue(p);
        printf("[%llu]: %llu\n", getPropertyFieldId(p), *v);
        Property* p2 = getNextProperty(p);
        freeMemory(v);
        disposeOfProperty(p);
        p = p2;
    }

    disposeOfObject(o);

    return 0;
}