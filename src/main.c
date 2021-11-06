#include<stdio.h>
#include "pb/parser.h"

int main(){
    FILE* f = fopen("_sample/test.bin", "rb");
    if(f == NULL){
        printf("Blad\n");
        return 1;
    }

    Object* o = readObjectFromStream(f, 8);
    fclose(f);

    Property* p = getObjectFirstProperty(o);
    void* v = getPropertyValue(p);
    printf("%d\n", *(int*)v);


    return 0;
}