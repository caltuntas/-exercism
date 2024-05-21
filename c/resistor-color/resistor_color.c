#include "resistor_color.h"

resistor_band_t resistors[] = {
  BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE,
};
resistor_band_t* colors() {
  return resistors;
}

int color_code(resistor_band_t c) {
  return (int)c;
}

