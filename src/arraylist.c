#include "arraylist.h"

// Metadata for generic arrays
typedef struct
{
    size_t length;
    size_t capacity;
    size_t itemsize;

} array_t;

array_t *get_array(void *handle)
{
    array_t *array = handle;
    return handle - 1;
}

void *array(size_t itemsize, size_t capacity)
{
    array_t *arr    = malloc(sizeof(array_t) + capacity * itemsize);
    arr->length     = capacity;
    arr->capacity   = capacity;
    arr->itemsize   = itemsize;

    // Return pointer to first element in array
    return arr + 1;
}

int array_setlength(void *handle, size_t length)
{
    array_t *array = get_array(handle);

    if (length <= array->capacity) {
        array->length = length;
        return 0;
    }
    return -1;
}

size_t array_length(void *handle)
{
    return get_array(handle)->length;
}

size_t array_capacity(void *handle)
{
    return get_array(handle)->capacity;
}

void *array_resize(void *handle, size_t capacity)
{
    array_t *array      = get_array(handle);
    array_t *new_array  = realloc(array,
        sizeof(array_t) + capacity * array->itemsize);
    new_array->capacity = capacity;


    if (new_array->length > capacity) {
        new_array->length = capacity;
    }

    // Return pointer to first element in new array
    return new_array + 1;
}

void *array_growif(void *handle, size_t(*cond)(size_t, size_t))
{
    array_t *array  = get_array(handle);
    int grow        = cond(array->length, array->capacity);

    // Resize array to support nitems + grow items
    if (grow > 0) {
        handle = array_resize(handle, array->capacity + grow);
    }
    return handle;
}

void array_free(void *handle)
{
    free(get_array(handle));
}
