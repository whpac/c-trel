#include<stdio.h>
#include "pb/parser.h"

int main(){
    FILE* f = fopen("_sample/test.bin", "rb");
    if(f == NULL){
        printf("Blad\n");
        return 1;
    }

    int64 x = readFixed64(f);
    fclose(f);

    printf("%2x %2x %2x %2x %2x %2x %2x %2x\n",
        x.byte0, x.byte1, x.byte2, x.byte3,
        x.byte4, x.byte5, x.byte6, x.byte7);

    return 0;
}