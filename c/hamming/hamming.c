#include "hamming.h"
#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs) {
  if((lhs==NULL) || (rhs==NULL)){
    return -1;
  }

  int count = 0;
  int i;
  int lenl = strlen(lhs);
  int lenr = strlen(rhs);

  if (lenr != lenl) {
    return -1;
  }

  for (i=0; i<lenl; i++) {
    char cl = lhs[i];
    char cr = rhs[i];

    if (cl != cr) {
      count++;
    }
  }

  return count;
}
