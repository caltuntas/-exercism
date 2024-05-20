#include "binary.h"

int convert(const char *input) {
  const char *p = input;
  const char *t = input;
  int len = 0;
  while (*t !='\0') {
     len++;
     t++;
  }

  int total = 0;
  while (*p !='\0') {
    int num = (int)*p - 48;
    if (num > 1) return -1;
    total += num << (len-1);
    p++;
    len--;
  }
  return total;
}
