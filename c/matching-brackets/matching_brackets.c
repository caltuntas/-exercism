#include "matching_brackets.h"
#include <string.h>
#include <stdlib.h>


bool is_paired(const char *input)
{
  char *stack =calloc(strlen(input),sizeof(char));
  if (stack == NULL) return false;

  char *top = stack;

  while(*input){
    char c = *input;
    if (c == '[' || c == '{' || c == '('){
      *top = c;
      top++;
    }

    if (c == ']' || c == '}' || c == ')'){
      char last_opening = *(top-1);

      if ((c == ']' && last_opening == '[' ) ||
          (c == '}' && last_opening == '{' ) ||
          (c == ')' && last_opening == '(' ) )
        top--;
      else {
        free(stack);
        return false;
      }
    }

    input++;
  }
  bool balanced = (top == stack);
  free(stack);
  return balanced;
}

