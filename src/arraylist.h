#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>

/*
 * Initial capacity of array
 */
void *array(size_t item_size, size_t nitems);

size_t array_length(const void *array);

/* Grows the array such that
 * nitems = nitems + 1
 */
void *array_grow(void *array);

size_t array_cap(const void *array);

#endif /* end of include guard: ARRAYLIST_H */
