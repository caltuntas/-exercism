#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  uint64_t left = n;
  //for (uint64_t i=2; i<n; i++)
  int divisor = 2;
  size_t count =0;
  while (left > 1 )
  {
    if (left % divisor == 0)
    {
      left = left / divisor;
      factors[count] = divisor;
      count++;
    }
    else
      divisor++;
  }
  return count;
}
