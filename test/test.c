#include <stdio.h>
#include "arraylist.h"

int main(int argc, const char *argv[])
{
    int *intarr = array(sizeof(int), 0);
    //intarr = array_grow(intarr);
    //printf("%lu\n", array_length(intarr));
    for (int i = 0; i < 10; i ++) {
        intarr = array_grow(intarr);
        intarr[i] = i;
    }
    for (int i = 0; i < array_length(intarr); i++) {
        printf("%d\n", intarr[i]);
    }
    printf("intarr cap = %lu\n", array_cap(intarr));
    return 0;
}
