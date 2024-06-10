#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
  if (length == 0)
    return NULL;
  int first = 0, last = length;
  int middle = length / 2;

  while (first != last)
  {
    if (arr[middle] == value)
      return &arr[middle];
    if (arr[middle] > value)
    {
      last = middle -1;
    }
    if (arr[middle] < value)
    {
      first = middle +1;
    }

    middle = (first + last) / 2;
  }
  return arr[middle] == value ? &arr[middle]:NULL;
}

