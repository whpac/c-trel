#include<stdio.h>
#include "typedefs.h"
#include "pb/parser.h"

int main(){
    FILE* f = fopen("_sample/test.bin", "rb");
    if(f == NULL){
        printf("Blad\n");
        return 1;
    }

    Object* o = readObjectFromStream(f, 13);
    fclose(f);

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