#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>


bool is_armstrong_number(int candidate) {
  if (candidate<0) {
    return false;
  }
  if (candidate==0) {
    return true;
  }
  int digits = 0;
  int i = 1;
  int division = candidate;
  for (i=1;  division > 0; i=i*10) {
    division = candidate / i;
    if (division >= 1) {
      digits++;
    }
  }

  int leftover=candidate;
  int sum =0;
  for (i = digits; i >0; i--) {
    int p = pow(10,i-1);
    int number = leftover / p;
    leftover = leftover % p;
    sum += pow(number, digits);
  }

  if (sum == candidate) {
    return true;
  }
  return false;
}
