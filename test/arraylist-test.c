#include <stdio.h>
#include "arraylist.h"

//#define ADD_ONE(len, cap) (len == cap) ? 1 : 0;

size_t add_one(size_t len, size_t cap)
{
    return (len == cap) ? 1 : 0;
}

int main(int argc, const char *argv[])
{
    /*int *intarr = array(sizeof(int), 0);
    //intarr = array_grow(intarr);
    //printf("%lu\n", array_length(intarr));
    for (int i = 0; i < 10; i ++) {
        intarr = array_grow(intarr);
        intarr[i] = i;
    }
    for (int i = 0; i < array_length(intarr); i++) {
        printf("%d\n", intarr[i]);
    }
    printf("intarr cap = %lu\n", array_cap(intarr));*/

    int *intarr = array(sizeof(int), 0);
    for (int i = 0; i < 10; i++) {
        intarr = array_growif(intarr, add_one);
        array_setlength(intarr, array_capacity(intarr));
        intarr[i] = i;
    }
    array_setlength(intarr, 10);

    for (int i = 0; i < array_length(intarr); i++) {
        printf("%d\n", intarr[i]);
    }
    printf("intarr cap = %lu\n", array_capacity(intarr));
    return 0;
}
