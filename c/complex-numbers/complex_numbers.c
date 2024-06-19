#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t c)
{
  return (complex_t) { a.real + c.real, a.imag+ c.imag};
}

complex_t c_sub(complex_t a, complex_t c)
{
  return (complex_t) { a.real - c.real, a.imag- c.imag};
}

complex_t c_mul(complex_t a, complex_t c)
{
  return (complex_t) { (a.real * c.real) - (a.imag * c.imag),  a.imag * c.real + a.real * c.imag};
}

complex_t c_div(complex_t a, complex_t c)
{
  double dividor = c.real*c.real+ c.imag * c.imag;
  return (complex_t) { 
    (a.real * c.real + a.imag * c.imag) / dividor,
      (a.imag*c.real-a.real*c.imag) / dividor};
}

double c_abs(complex_t x)
{
  return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
  return (complex_t){ x.real, -1*x.imag};
}

double c_real(complex_t x)
{
  return x.real;
}

double c_imag(complex_t x)
{
  return x.imag;
}

complex_t c_exp(complex_t x)
{
  return (complex_t){ exp(x.real)* cos(x.imag) , exp(x.real)*sin(x.imag)};
}
