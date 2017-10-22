#include <stdio.h>
#include "array.h"

int main(int argc, char const *argv[])
{
  unique_array(int) numbers = array_alloc(sizeof(int), 10);
  printf("numbers.length = %lu\n", array_length(numbers));

  for (int i = 0; i < array_length(numbers); i++) {
    numbers[i] = i * 2;
  }
  for (int i = array_length(numbers) - 1; i >= 0; i--) {
    printf("%d\n", numbers[i]);
  }

  return 0;
}
