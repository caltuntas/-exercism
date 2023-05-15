#include "grains.h"
#include <math.h>

uint64_t square(uint8_t index) {
  if (index <=0 || index > 64 ) {
    return 0;
  }
  return pow(2, index-1);

}

uint64_t total(void) {
  int i;
  int total= 0;
  for (i = 0; i<=64; i++ ) {
    total += square(i);
  }
  return total;
}
