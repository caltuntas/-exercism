#include "clock.h"

static time_t parse_time(clock_t clock)
{
  char* token = strtok(clock.text, ":");
  int hours = (int) strtol(token, (char **)NULL, 10);
  token = strtok(NULL, ":");
  int minutes = (int) strtol(token, (char **)NULL, 10);
  return (time_t){hours,minutes};
}

clock_t clock_create(int hour, int minute)
{
  clock_t clock = {0};
  int totalmins = hour * 60 + minute;
  int hours =(((int)floor((24*60.0 +totalmins) / 60.0) % 24) +24) % 24;
  int minutes = totalmins % 60;
  minutes = minutes < 0 ? minutes+60:minutes;
  sprintf(clock.text,"%02d:%02d",hours,minutes);
  return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
  time_t t = parse_time(clock);
  return clock_create(t.hour, t.minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
  time_t t = parse_time(clock);
  return clock_create(t.hour, t.minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b)
{
  return strcmp(a.text,b.text) ==0;
}

