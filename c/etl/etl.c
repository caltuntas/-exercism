#include "etl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
  int letters[26] = {0};
  int len =0;
  for (size_t i=0; i<input_len; i++) {
    len +=strlen(input[i].keys);
  }

  new_map *map =calloc(len,sizeof *map);
  for (size_t i=0; i<input_len; i++) {
    size_t key_len =strlen(input[i].keys);
    for (size_t j=0; j<key_len; j++) {
      char c =tolower(input[i].keys[j]);
      int idx = c-'a';
      letters[idx] = input[i].value;
    }
  }

  for (size_t i=0, j=0; i<26; i++) {
    if (letters[i]) {
      map[j].key =i + 'a';
      map[j].value = letters[i];
      j++;
    }
  }
  *output = map;
  return len;
}
