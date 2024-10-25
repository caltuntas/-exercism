#include "atbash_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

char *atbash_encode(const char *input) {
  size_t len = strlen(input);
  char* encoded = calloc(len*2,sizeof(char));
  size_t counter =1,spaces =0;
  bool add_space = false;

  for(size_t i=0; i<len; i++) {
    char c = tolower(input[i]);
    if(!isalpha(c) && !isdigit(c)) continue;

    if (isalpha(c)) {
      c = 'a' + 'z' - c;
    }

    if (add_space) {
      encoded[counter-1] = ' ';
      counter++;
      spaces++;
      add_space = false;
    }

    encoded[counter-1] = c;
    add_space = (counter-spaces) % 5 == 0;
    counter++;
  }
  return encoded;
}

char *atbash_decode(const char *input) {
  size_t len = strlen(input);
  char* decoded = calloc(len,sizeof(char));
  size_t counter =0;
  for(size_t i=0; i<len; i++) {
    char c = tolower(input[i]);
    if(isalpha(c) || isdigit(c)) {
      if(isalpha(c)) {
        c = 'a' + 'z' - c;
      }
      decoded[counter] = c;
      counter++;
    }
  }
  return decoded;
}
