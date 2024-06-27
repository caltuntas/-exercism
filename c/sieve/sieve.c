#include "sieve.h"
#define IS_PRIME (1)
#define IS_NOT_PRIME (0)

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  uint32_t numbers[limit+1];
  memset(numbers,IS_PRIME,sizeof(uint32_t)*(limit+1));

  for (uint32_t i=2; i<=limit ; i++)
  {
    if (numbers[i])
    {
      for (uint32_t j=i*i; j<=limit; j+=i)
      {
          numbers[j] = IS_NOT_PRIME;
      }
    }
  }

  uint32_t count =0;

  for (uint32_t i=2; count<max_primes && i<=limit; i++)
  {
    if (numbers[i]) 
    {
      primes[count] = i;
      count++;
    }
  }

  return count;
}
