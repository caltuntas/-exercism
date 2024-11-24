#include "diamond.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **make_diamond(const char letter)
{
  int diff = letter - 'A';
  int rows = diff * 2 + 1;
  int shift = diff;
  int inc = -1;
  char **diamond = calloc(rows,sizeof *diamond);
  for( int i=0; i<rows; i++) {
    char *row = calloc(rows+1,sizeof row);
    memset(row,' ',rows);
    for( int j=0; j<rows; j++) {
      if (j == shift || j == (rows-shift -1)) 
        row[j] = letter - shift;
    }
    if (shift == 0)
      inc = 1;
    shift += inc;
    diamond[i] = row;
  }
  return diamond;
}

void free_diamond(char **diamond)
{
  char **current = diamond;
  while(*current !=NULL) {
    free(*current);
    current++;
  }
  free(diamond);
}


