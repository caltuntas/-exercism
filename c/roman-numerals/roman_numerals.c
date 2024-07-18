#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

unsigned int numbers[] ={1000,900, 500,400,100,90, 50,40, 10,9,5,4,1};
char *letters[] = { "M","CM", "D","CD", "C","XC", "L","XL", "X","IX", "V","IV", "I"};

char *to_roman_numeral(unsigned int number)
{
  char *roman = calloc(10,sizeof(char));
  if (roman == NULL) return NULL;
  unsigned int remaining = number, biggest =0;
  for (size_t i=0; remaining > 0; remaining -=biggest){
    for (i=0; i<ARRAY_LEN(numbers); i++) {
      if (remaining >= numbers[i]) {
        biggest = numbers[i];
        break;
      }
    }
    strncat(roman,letters[i],strlen(letters[i]));
  }
  return roman;
}
