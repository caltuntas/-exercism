#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
  char *newtext = malloc(strlen (text) + 1);
  if (newtext == NULL) return NULL;
  strcpy(newtext, text);
  for (size_t i =0; i<strlen(newtext); i++)
  {
    unsigned char chr = newtext[i];
    if (isalpha(chr)){
      unsigned char base = (chr & 1 << 5) + 'A';
      newtext[i] = base + (chr - base + shift_key) % 26;
    }
  }
  return newtext;
}
