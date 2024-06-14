#include "triangle.h"

static int check(triangle_t t)
{
  return t.a + t.b >= t.c
    && t.b +t.c >= t.a
    && t.a + t.c >= t.b;
}

int is_equilateral(triangle_t t)
{
  return check(t) && t.a == t.b && t.a == t.c && t.a >0;
}
int is_isosceles(triangle_t t)
{
  return check(t) && (t.a == t.b || t.b == t.c || t.a == t.c);
}
int is_scalene(triangle_t t)
{
  return check(t) && !is_isosceles(t) ;
}

