#include "two_fer.h"

void two_fer(char *buffer, const char *name) {
  const char *str = name == NULL ? "you" : name;
  sprintf(buffer, "One for %s, one for me.",str);
}

