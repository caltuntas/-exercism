#include "nth_prime.h"

static bool is_prime(uint32_t number)
{
  for (uint32_t i=2; i*i<=number; i++)
  {
    if ( number % i == 0)
      return false;
  }
  return true;
}

uint32_t nth(uint32_t n)
{
  uint32_t count = 0;
  for (int i=2; count!=n ; i++)
  {
    if(is_prime(i) && ++count ==n )
      return i;
  }
  return n;
}
