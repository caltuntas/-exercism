#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) 
{
  unsigned int numbers[limit];
  memset(numbers,0,limit * sizeof(unsigned int));
  for (size_t i=0; i<number_of_factors; i++)
  {
    unsigned int factor = factors[i];
    for (size_t j=factor; j<limit && factor>0; j++)
    {
      if (j % factor == 0)
        numbers[j] = j;
    }
  }

  unsigned int result = 0;
  for (size_t i=0; i<limit; i++)
  {
    result += numbers[i];
  }
  return result;
}
