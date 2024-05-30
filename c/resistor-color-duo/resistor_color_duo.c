
#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t r[]){
  return r[0]*10 + r[1];
}
