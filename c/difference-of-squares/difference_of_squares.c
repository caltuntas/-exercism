#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int sum) {
  unsigned int i;
  unsigned int total=0;
  for(i =1; i<=sum; i++) {
    total+=i;

  }
  return total * total;
}

unsigned int sum_of_squares(unsigned int n) {
  unsigned int i;
  unsigned int sum=0;
  for(i =1; i<=n; i++) {
    sum+=(i*i);

  }
  return sum;
}

unsigned int difference_of_squares(unsigned int n) {
  unsigned int sumOfSquares = sum_of_squares(n);
  unsigned int squaresOfSum = square_of_sum(n);
  return  squaresOfSum-sumOfSquares;
}
