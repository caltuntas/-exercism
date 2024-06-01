#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int n) {
  int count = 0;
  int num = n;
  while(num != 0) {
    num = num & (num-1);
    count++;
  }
  return count;
}
