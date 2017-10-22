#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef void* array_t;

array_t array_alloc(size_t item_size, size_t length);
void    array_free(array_t array);
size_t  array_length(array_t array);

// Primitive types
void __clean_char(char**);
void __clean_short(short**);
void __clean_int(int**);
void __clean_long(long**);
void __clean_float(float**);
void __clean_double(double**);

#define REG_UNIQUE_TYPE(ty)\
  void __clean_ ## ty(ty** tref) {\
    if (tref != NULL) array_free(*tref); }

#define unique_array(ty)\
  __attribute__((cleanup (__clean_ ## ty))) ty*

#endif
