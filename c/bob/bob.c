#include "bob.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

static char *whatever = "Whatever.";
static char *sure = "Sure.";
static char *chill_out = "Whoa, chill out!";
static char *calm_down = "Calm down, I know what I'm doing!";
static char *fine = "Fine. Be that way!";

char *hey_bob(char *greeting)
{
  bool contains_upper=false, contains_lower=false, contains_space=false, contains_digit=false, contains_punct=false;
  bool ends_with_question = false;
  char last_char = 0;
  if (!*greeting)
    return fine;

  for (; *greeting; greeting++) {
    contains_upper |=isupper(*greeting);
    contains_lower |=islower(*greeting);
    contains_punct |=ispunct(*greeting);
    contains_digit |=isdigit(*greeting);

    if (isspace(*greeting))
      contains_space = true;
    else 
      last_char = *greeting;
  }

  if (last_char == '?')
    ends_with_question = true;

  if (contains_upper && !contains_lower && !ends_with_question)
    return chill_out;

  if (contains_upper && !contains_lower && ends_with_question)
    return calm_down;

  if (ends_with_question) 
    return sure;

  if (contains_space && !contains_upper && !contains_lower && !contains_digit && !contains_punct)
    return fine;

  return whatever;
}
