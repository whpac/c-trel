#include<stdio.h>
#include "pb/parser.h"

int main(){
    FILE* f = fopen("_sample/test.bin", "rb");
    if(f == NULL){
        printf("Blad\n");
        return 1;
    }

    unsigned long long x = readVarint(f, NULL);
    fclose(f);

    printf("%llu\n", x);

    return 0;
}