#include "rational_numbers.h"

static int gdc(int num1, int num2)
{
  if (num1 ==0) return num2;
  if (num2 ==0) return num1;
  int min = abs(num1) < abs(num2)?abs(num1):abs(num2);
  int result = 1;
  for (int i=1; i<=min; i++)
  {
    if (num1 % i == 0 && num2 % i == 0)
      result =i;
  }
  return result;
}

rational_t reduce(rational_t r1)
{
  rational_t r;
  int a = gdc(r1.numerator, r1.denominator);
  r.numerator = r1.numerator / a;
  r.denominator = r1.denominator / a;
  if (r.numerator > 0 && r.denominator <0)
  {
    r.numerator *= -1;
    r.denominator *= -1;
  }

  if( r.numerator < 0 && r.denominator< 0)
  {
    r.numerator *= -1;
    r.denominator *= -1;
  }
  return r;
}

rational_t add(rational_t r1, rational_t r2)
{
  rational_t r;
  r.numerator = (r1.numerator*r2.denominator + r2.numerator*r1.denominator);
  r.denominator= (r1.denominator*r2.denominator);
  return reduce(r);
}

rational_t subtract(rational_t r1, rational_t r2)
{
  rational_t r;
  r.numerator = (r1.numerator*r2.denominator - r2.numerator*r1.denominator);
  r.denominator= (r1.denominator*r2.denominator);
  return reduce(r);
}

rational_t multiply(rational_t r1, rational_t r2)
{
  rational_t r;
  r.numerator = (r1.numerator*r2.numerator);
  r.denominator= (r1.denominator*r2.denominator);
  return reduce(r);
}

rational_t divide(rational_t r1, rational_t r2)
{
  rational_t r;
  r.numerator = (r1.numerator*r2.denominator);
  r.denominator= (r1.denominator*r2.numerator);
  return reduce(r);
}

rational_t absolute(rational_t r1)
{
  rational_t r;
  r.numerator = abs(r1.numerator) ;
  r.denominator = abs(r1.denominator) ;
  return reduce(r);
}

float exp_real(uint16_t x, rational_t r1)
{
  float result = pow(x, (float)r1.numerator / r1.denominator);
  return result;
}

rational_t exp_rational( rational_t r1, int16_t n)
{
  rational_t r;
  if (n > 0) 
  {
    r.numerator = pow(r1.numerator,n);
    r.denominator = pow(r1.denominator,n);
  } 
  else
  {
    r.numerator = pow(r1.denominator,abs(n));
    r.denominator = pow(r1.numerator,abs(n));
  }
  return reduce(r);
}
