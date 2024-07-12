#include "phone_number.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *phone_number_clean(const char *input)
{
  char *str = calloc(strlen(input),sizeof *str);
  if (str == NULL) return NULL;

  int count =0;
  while(*input) {
    if (isdigit(*input) && !(count == 0 && *input == '1') ) {
      str[count++] = *input;
    }
    input++;
  }

  if (count != 10)
    strncpy(str,"0000000000\0",11);
  else if(str[0] < '2' || str[3] < '2')
    strncpy(str,"0000000000\0",11);
  return str;
}
