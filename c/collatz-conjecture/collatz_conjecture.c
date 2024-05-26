#include "collatz_conjecture.h"

int steps(int start) {
  if (start <= 0 )
    return ERROR_VALUE;
  int steps = 0;
  int result = start;
  while ( result != 1) {
    if ((result & 1) == 0) 
      result = result >> 1;
    else 
      result = result * 3 + 1;

    steps++;
  }
  return steps;
}

