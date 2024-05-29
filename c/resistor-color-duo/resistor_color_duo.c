
#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t r[]){
  char str[10];
  str[0] = '\0';
  resistor_band_t *p = r;
  int i = 0;
  while(*p >= BLACK && *p <= WHITE && i < 2) {
    char c = *p + '0';
    printf("%c=",c);
    strncat(str,&c,1);
    p++;
    i++;
  }
  return strtol(str,NULL, 10);
}
