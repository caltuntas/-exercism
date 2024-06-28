#include "reverse_string.h"

char *reverse(const char *value)
{
  char* str = malloc(sizeof(char)*strlen(value));
  if (str == NULL) abort();
  for (int j=0, i = strlen(value)-1; i>=0; i--, j++)
  {
    str[j] = value[i];
  }
  return str;
}

