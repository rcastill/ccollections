#include "array.h"
#include <stdlib.h>

REG_UNIQUE_TYPE(char)
REG_UNIQUE_TYPE(short)
REG_UNIQUE_TYPE(int)
REG_UNIQUE_TYPE(long)
REG_UNIQUE_TYPE(float)
REG_UNIQUE_TYPE(double)

typedef struct {
  size_t item_size;
  size_t length;
} __array_meta_t;

void _clean_array(array_t* arr_ref)
{
  if (arr_ref != NULL) {
    free(*arr_ref);
  }
}

void* array_alloc(size_t item_size, size_t length)
{
  __array_meta_t* meta =
    malloc(sizeof(*meta) + item_size * length);
  meta->item_size      = item_size;
  meta->length         = length;
  return meta + 1;
}

void array_free(array_t array)
{
  // Get metadata
  __array_meta_t* meta = array; meta -= 1;
  free(meta);
}

size_t array_length(array_t array)
{
  // Get metadata
  __array_meta_t* meta = array; meta -= 1;
  return meta->length;
}

void array_iterate(array_t array, void(*it)(size_t,void*))
{
  __array_meta_t* meta = array; meta -= 1;
  char* data           = array;

  for (size_t i = 0; i < meta->length; i++) {
    it(i, data + i * meta->item_size);
  }
}
