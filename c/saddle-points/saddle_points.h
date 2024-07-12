#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct {
  uint8_t row;
  uint8_t column;
} saddle_point_t;

typedef struct {
  size_t count;
  saddle_point_t *points;
} saddle_points_t;

saddle_points_t* saddle_points(size_t x, size_t y, uint8_t matrix[x][y]);
void free_saddle_points(saddle_points_t *p);

#endif
