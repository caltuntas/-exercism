#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
  time_t gigasecond = 1000000000;
  time_t total = input + gigasecond;
  const struct tm *t = gmtime(&total);
  strftime(output,size,"%Y-%m-%d %H:%M:%S",t);
}

