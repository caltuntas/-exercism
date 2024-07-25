#include "bob.h"
#include <stdbool.h>
#include <ctype.h>

char *hey_bob(char *greeting)
{
  bool contains_upper=false, contains_lower=false, only_space=true;
  char last_char = 0;

  for (; *greeting; greeting++) {
    if (!isspace(*greeting)){
      only_space = false;
      contains_upper |=isupper(*greeting);
      contains_lower |=islower(*greeting);
      last_char = *greeting;
    } 
  }

  if (contains_upper && !contains_lower && last_char !='?') return "Whoa, chill out!";
  if (contains_upper && !contains_lower && last_char =='?') return "Calm down, I know what I'm doing!";
  if (last_char == '?') return "Sure.";
  if (only_space) return "Fine. Be that way!";
  return "Whatever.";
}
