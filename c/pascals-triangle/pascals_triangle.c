#include "pascals_triangle.h"
#include <stdlib.h>
#include <stdio.h>

uint8_t **create_triangle(size_t rows)
{
  size_t size =rows;
  if (rows ==0) size ++;
  uint8_t **triangle = calloc(size, sizeof(uint8_t*));
  for (size_t i=0; i<size; i++)
    triangle[i] = calloc(size, sizeof (uint8_t*));

  for (size_t i = 0; i < size && rows>0; ++i) {
    for (size_t j = 0; j <= i; j++)
    {
      size_t row1i = i>1?i-1:0;
      size_t row1j = j>1?j-1:0;
      size_t row2i = row1i;
      size_t row2j = j;
      if (j==0)
        triangle[i][j] =1;
      else
        triangle[i][j] =triangle[row1i][row1j]+triangle[row2i][row2j];
    }
  }

  return triangle;
}

void free_triangle(uint8_t **triangle, size_t rows)
{  
  if (triangle) {
    for (size_t i = 0; i < rows; i++)
      if (triangle[i])
        free(triangle[i]);
    free(triangle);
  }
}

