#include "arraylist.h"
#include <stdio.h>

// We need DEFAULT_CAP to be at least 2
#ifndef DEFAULT_CAP
    #define DEFAULT_CAP 2
#elif DEFAULT_CAP < 2
    #define DEFAULT_CAP 2
#endif

// Metadata for generic arrays
typedef struct
{
    size_t nitems;
    size_t cap;
    size_t itemsize;

} array_t;

// Generic array constructor
void *array(size_t itemsize, size_t nitems)
{
    // Set initial capacity
    size_t cap = (nitems < DEFAULT_CAP) ?
        DEFAULT_CAP : nitems;
    // Allocate metadata for array
    array_t *holder = malloc(sizeof(array_t));
    // Initialize holder
    holder->nitems = nitems;
    holder->cap = cap;
    holder->itemsize = itemsize;
    // Allocate space to store cap * nitems bytes
    // plus a pointer to the holder 
    array_t **arr = malloc(sizeof(array_t*) +
            cap * itemsize);
    // Set element (-1) as the metadata
    *arr = holder;
    // Return next space as the beginning
    // of the array
    return arr + 1;
}

// Get array metadata as const
const array_t *get_holder_const(const void *array)
{
    array_t * const *self = array;
    return *(self - 1);
}

// Get array metadata as mutable
array_t *get_holder(void *array)
{
    array_t **self = array;
    return *(self - 1);
}

// Get array length (nitems)
size_t array_length(const void *array)
{
    return get_holder_const(array)->nitems;
}

size_t array_cap(const void *array)
{
    return get_holder_const(array)->cap;
}

// Grow array
void *array_grow(void *array)
{
    // Get current metadata
    array_t *holder = get_holder(array);
    // Reference new array
    array_t **new_arr = array; new_arr--;
    // Modify metadata if necessary
    if (holder->nitems == holder->cap) {
        holder->cap += holder->cap / 2;
        new_arr = realloc(new_arr, sizeof(array_t*) +
                holder->cap * holder->itemsize);
        holder = *new_arr;
    }
    holder->nitems++;
    return new_arr + 1;
}

