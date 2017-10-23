#include <stdio.h>
#include "array.h"

void array_consumer(size_t i, void* obscure_item)
{
  int* item = obscure_item;
  printf("numbers[%lu] = %d\n", i, *item);
}

void set_squared(size_t i, void* obscure_item)
{
  int* item = obscure_item;
  *item = i * 2;
}

int main(int argc, char const *argv[])
{
  unique_array(int) numbers = array_alloc(sizeof(int), 10);
  printf("array_length(numbers) = %lu\n", array_length(numbers));
  array_iterate(numbers, set_squared);
  array_iterate(numbers, array_consumer);

  return 0;
}
