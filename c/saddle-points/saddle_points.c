#include "saddle_points.h"

static void add_point(saddle_points_t *p,uint8_t col,uint8_t row)
{
  p->count++;
  saddle_point_t *new_points = realloc(p->points,p->count * sizeof(saddle_point_t));
  p->points = new_points;
  p->points[p->count-1].row =row +1;
  p->points[p->count-1].column =col +1;
}

static uint8_t max(size_t len, uint8_t array[])
{
  uint8_t res=0;
  for(size_t i=0; i<len; i++)
    if(array[i] > res) 
      res = array[i];

  return res;
}

static bool is_saddle(size_t row,size_t col,size_t row_count,size_t col_count,uint8_t matrix[row_count][col_count])
{
  uint8_t min = matrix[row][col];
  for (size_t j = 0; j < row_count; ++j) {
    uint8_t val = matrix[j][col];
    if (val < min)
      return false;
  }
  return true;
}


static void find_saddle_points(saddle_points_t *p,uint8_t max_val,size_t row,size_t row_count, size_t col_count, uint8_t matrix[row_count][col_count])
{
  for (size_t i=0; i<col_count; i++)
  {
    uint8_t current_val = matrix[row][i];
    if (current_val == max_val)
    {
      bool saddle = is_saddle(row,i,row_count,col_count,matrix);
      if (saddle)
        add_point(p,i,row);
    }
  }
}


saddle_points_t* saddle_points(size_t x, size_t y, uint8_t matrix[x][y])
{
  saddle_points_t *p = malloc(sizeof(saddle_points_t));
  p->points = NULL;
  p->count = 0;

  for (size_t i = 0; i < x; ++i) {
    size_t max_in_row = max(y,matrix[i]);
    find_saddle_points(p,max_in_row,i,x,y,matrix);
  }

  return p;
}

void free_saddle_points(saddle_points_t *p)
{
  if(p)
  {
    if (p->points != NULL)
      free(p->points);
    free(p);
  }
}

