#include "series.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length)
{
  char **list = NULL;

  slices_t s = {0};
  int counter =0;
  size_t len = strlen(input_text);
  for (size_t i=0; i<len && substring_length > 0; i++) {
    if (i+substring_length <= len) {
      list = realloc(list,sizeof(list)*(++counter));
      char *substr =calloc(substring_length+1, sizeof(char));
      strncpy(substr,input_text+i,substring_length);
      list[i] =substr;
    }
  }

  s.substring_count = counter;
  s.substring =list;
  return s;
}
