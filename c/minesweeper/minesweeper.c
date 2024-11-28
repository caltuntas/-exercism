#define _GNU_SOURCE
#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **annotate(const char **minefield, const size_t rows){
  if (minefield == NULL)
    return NULL; 

  char **field = calloc(rows+1, sizeof *field);
  for(size_t i=0; i<rows;i++) {
    char* cols = strdup(minefield[i]);
    field[i] = cols;
  }

  for(size_t i=0; i<rows;i++) {
    size_t len = strlen(field[i]);
    for(size_t j=0; j<len;j++) {
      char* row = field[i];
      if(row[j] != ' ') continue;
      int count =0;
      for(size_t k = i?(i-1):0; k<i+2;k++) {
        if (k>=rows)
          continue;
        for(size_t l = j?(j-1):0; l<j+2;l++) {
          if (l>=len || (i==k && j==l))
            continue;
          count+=field[k][l] == '*';
        }
      }
      if(count>0)
        row[j] = count + '0';
    }
  }
       
  return field;
}

void free_annotation(char **annotation){
  char **current = annotation;
  while(*current) {
    free(*current);
    current++;
  }
  free(annotation);
}
