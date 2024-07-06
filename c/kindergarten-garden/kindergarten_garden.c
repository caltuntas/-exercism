#include "kindergarten_garden.h"
#include <string.h>

plants_t plants(const char* diagram, const char *student)
{
  char *names[12] ={ "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
  int index =0;
  while (index<12 && strcmp(student,names[index])!=0) index++;

  index *=2;
  int inc = (strlen(diagram)+1) / 2;

  char lookup[] = {
    ['C'] =CLOVER,
    ['G'] =GRASS,
    ['R'] =RADISHES,
    ['V'] =VIOLETS
  };

  plants_t p = {0};
  p.plants[0] = lookup[(int)diagram[index]];
  p.plants[1] = lookup[(int)diagram[index + 1]];
  p.plants[2] = lookup[(int)diagram[index + inc]];
  p.plants[3] = lookup[(int)diagram[index + 1 + inc]];
  return p;
}
