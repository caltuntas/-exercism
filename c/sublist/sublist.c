#include "sublist.h"

comparison_result_t check_lists(int *list1, int *list2, size_t count1, size_t count2)
{
  if (list1 == NULL && list2 == NULL)
    return EQUAL;
  if (list1 == NULL && list2 != NULL)
    return SUBLIST;
  if (list1 != NULL && list2 == NULL)
    return SUPERLIST;

  if(count1 == count2)
  {
    for (size_t i=0; i<count1; i++)
    {
      if (list1[i] != list2[i])
        return UNEQUAL;
    }
    return EQUAL;
  }

  comparison_result_t success_result = SUBLIST;

  comparison_result_t res = UNEQUAL;
  if (count2 < count1)
  {
    int *tmplist = list1;
    list1 = list2;
    list2 = tmplist;

    size_t tmpcount = count1;
    count1 = count2;
    count2 = tmpcount;
    success_result = SUPERLIST;
  }

  for (size_t i=0; i<count2; i++)
  {
    if (list2[i] != list1[0])
      continue;

    res = success_result;
    for (size_t j=1; j<count2 && j<count1; j++)
    {
      if (list1[j] != list2[i+j])
      {
        res = UNEQUAL;
        break;
      }
    }
    if ( res == success_result )
      return success_result;
  }
  return res;
}

