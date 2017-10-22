#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>

#define DEFAULT_GROWTH(len, cap) (len == cap) ? len / 2 : 0;

/*
 * Initial capacity of array
 */
void *array(size_t item_size, size_t capacity);

/*
 * Sets length attribute. This is metadata ONLY.
 * It will return 0 on success, that is, in the case
 * that 0 <= length <= capacity.
 * Otherwise it will return -1.
 */
int array_setlength(void *handle, size_t length);

/*
 * Get length of the array
 */
size_t array_length(void *handle);

size_t array_capacity(void *handle);

void *array_resize(void *handle, size_t capacity);

/*
 * Grows the capacity of the array if
 */
void *array_growif(void *handle, size_t(*cond)(size_t, size_t));

/*
 * Frees heap
 */
void array_free(void *handle);


#endif /* end of include guard: ARRAYLIST_H */
