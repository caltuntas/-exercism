#include "square_root.h"

int square_root(int n) {
  int i = 0;
  for (i=1; i<=n; i++) {
    int sqrt = i * i;
      if (sqrt == n) 
        return i;
  }
  return 0;
}
