#include "sublist.h"

static char* convert_to_str(int* list, size_t len)
{
  int digits =0;
  for (size_t i=0; i<len; i++)
  {
    int d = list[i];
    if (d == 0)
      digits++;
    else
      digits += (floor(log10(abs(d))) + 1);
    digits++;
  }
  int n=0;
  char* str = calloc(digits+1, sizeof *str);
  for (size_t i=0; i<len; i++)
  {
    n += sprintf(&str[n],"%d,",list[i]);
  }
  return str;
}

comparison_result_t check_lists(int *list1, int *list2, size_t count1, size_t count2)
{
  if (list1 == NULL && list2 == NULL) return EQUAL;
  if (list1 == NULL) return SUBLIST;
  if (list2 == NULL) return SUPERLIST;

  char *str1 = convert_to_str(list1,count1);
  char *str2 = convert_to_str(list2,count2);

  comparison_result_t res = UNEQUAL;
  if(count1 == count2)
    res= strcmp(str1, str2) == 0 ? EQUAL: UNEQUAL;
  else if (count2 < count1)
    res = strstr(str1, str2) != NULL?SUPERLIST:UNEQUAL;
  else 
    res = strstr(str2, str1) != NULL?SUBLIST:UNEQUAL;
  free(str1);
  free(str2);
  return res;
}
