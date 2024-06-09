#include "pangram.h"
#define ASCII_A 97
#define ASCII_Z 122
#define LETTER_COUNT 26

bool is_pangram(const char *sentence) 
{
  if (!sentence)
    return false;
  int i=0;
  char letters[LETTER_COUNT] = {0};
  memset(letters,'-',sizeof(letters));
  while(*sentence)
  {
    unsigned char chr = *sentence;
    // convert to lower case
    chr |= 1 << 5;
    if (chr >= ASCII_A && chr <= ASCII_Z && letters[chr-ASCII_A] == '-')
    {
      letters[chr-ASCII_A] = chr;
      i++;
    }

    sentence++;
  }
  return i == LETTER_COUNT;
}
