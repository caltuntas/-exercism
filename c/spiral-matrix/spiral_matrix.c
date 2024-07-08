#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
  spiral_matrix_t *m = malloc(sizeof(spiral_matrix_t));
  if (size <= 0) {
    m->size = 0;
    m->matrix = NULL;
    return m;
  }

  m->matrix = malloc(size * sizeof(int *));
  m->matrix[0] = (int *) malloc(size * size * sizeof(int));
  for (int i = 1; i < size; i++)
    m->matrix[i] = m->matrix[0] + i * size;

  m->size = size;

  int counter = 1;
  int left = 0, right = size - 1, top = 0, bottom = size - 1;

  while (left <= right && top <= bottom) {
    for (int j = left; j <= right; j++)
      m->matrix[top][j] = counter++;

    top++;

    for (int i = top; i <= bottom; i++)
      m->matrix[i][right] = counter++;

    right--;

    for (int j = right; j >= left; j--)
      m->matrix[bottom][j] = counter++;

    bottom--;

    for (int i = bottom; i >= top; i--)
      m->matrix[i][left] = counter++;

    left++;
  }

  return m;
}

void spiral_matrix_destroy(spiral_matrix_t *m)
{
  if (m) {
    if (m->matrix) {
        free(m->matrix[0]);
      free(m->matrix);
    }
    free(m);
  }
}
