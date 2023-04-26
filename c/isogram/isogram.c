#include "isogram.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool is_isogram(const char phrase[]) {
  if(phrase == NULL){
    return false;
  }
  if(phrase[0]=='\0') {
    return true;
  }

  int i;
  int j;
  int length = strlen(phrase);
  for(i=0; i< length; i++) {
    char c = tolower(phrase[i]);
    for(j=0; j< length; j++) {
      char currentChar = tolower(phrase[j]) ;
      if (j!=i && currentChar!=' ' && currentChar !='-' && currentChar == c) {
        return false;
      }
    }
  }
  return true;
}
