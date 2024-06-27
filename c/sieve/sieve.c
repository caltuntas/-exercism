#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  uint32_t unmarked[limit+1];

  for(uint32_t i=0; i<=limit; i++)
  {
    if ( i<2 ) unmarked[i] = 0;
    else unmarked[i] = i;
  }

  for (uint32_t i=0; i<=limit ; i++)
  {
    if (unmarked[i] > 0)
    {
      for (uint32_t j=i*i; j<=limit; j++)
      {
        if (i!=0 && j % i == 0)
          unmarked[j] = 0;
      }
    }
  }

  uint32_t count =0;

  for (uint32_t i=0; count<max_primes && i<=limit; i++)
  {
    if (unmarked[i] > 0) 
    {
      primes[count] = i;
      count++;
    }
  }

  return count;
}
