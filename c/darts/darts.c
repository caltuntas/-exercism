#include "darts.h"

static const float OUTER_CIRCLE_RADIUS = 10.0F;
static const float MIDDLE_CIRCLE_RADIUS = 5.0F;
static const float INNER_CIRCLE_RADIUS = 1.0F;

uint8_t score(coordinate_t coords) {
  float c2 = pow(coords.x,2) + pow(coords.y,2);
  if (c2 <= pow(INNER_CIRCLE_RADIUS,2))
    return 10;
  if (c2 <= pow(MIDDLE_CIRCLE_RADIUS,2))
    return 5;
  if (c2 <= pow(OUTER_CIRCLE_RADIUS,2))
    return 1;
  return 0;
}
