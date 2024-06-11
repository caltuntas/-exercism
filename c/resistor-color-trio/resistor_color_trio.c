#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t* r) 
{
  unsigned long long v =(r[0]*10 + r[1])*pow(10,r[2]);
  resistor_value_t val = {0,0};
  val.value = v;

  int i =0;
  while(v!=0 && v % 1000 == 0)
  {
    v = v / 1000;
    val.value = v;
    i++;
  }
  val.unit = i;

  return val;
}
