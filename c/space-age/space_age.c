#include "space_age.h"

#define EARTH_SECONDS 31557600

float age(planet_t planet, int64_t seconds) {
  if (planet == VENUS) {
    return seconds/EARTH_SECONDS/0.61519726;
  }
  if (planet == EARTH) {
    return seconds/EARTH_SECONDS/1;
  }
  if (planet == MERCURY) {
    return seconds/EARTH_SECONDS/0.2408467;
  }
  if (planet == MARS) {
    return seconds/EARTH_SECONDS/ 1.8808158 ;
  }
  if (planet == JUPITER) {
    return seconds/EARTH_SECONDS/ 11.862615 ;
  }
  if (planet == SATURN) {
    return seconds/EARTH_SECONDS/ 29.447498 ;
  }
  if (planet == URANUS) {
    return seconds/EARTH_SECONDS/ 84.016846 ;
  }
  if (planet == NEPTUNE) {
    return seconds/EARTH_SECONDS/ 164.79132 ;
  }
  return -1;
}
