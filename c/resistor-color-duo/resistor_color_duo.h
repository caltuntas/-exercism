#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  BLACK= 0,
  BROWN= 1,
  RED= 2,
  ORANGE= 3,
  YELLOW= 4,
  GREEN= 5,
  BLUE= 6,
  VIOLET= 7,
  GREY= 8,
  WHITE= 9
} resistor_band_t;

uint16_t color_code(resistor_band_t r[]);

#endif
