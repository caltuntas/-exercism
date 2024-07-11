#include "list_ops.h"
list_t *new_list(size_t length, list_element_t elements[])
{
  list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
  if (list == NULL) return NULL;
  list->length = length;
  for (size_t i=0; elements!=NULL && i<length; i++)
    list->elements[i] = elements[i];
  return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
  size_t len = list1->length+list2->length;
  list_element_t elements[len];
  size_t i=0;
  for (; i<list1->length; i++)
    elements[i] = list1->elements[i];
  for (size_t j=0; j<list2->length; j++,i++)
    elements[i] = list2->elements[j];
  list_t *list = new_list(len,elements);
  return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
  size_t count=0;
  for (size_t i=0; i<list->length; i++)
  {
    list_element_t e=list->elements[i];    
    bool result = (*filter)(e);
    if ( result) count++;
  }

  list_element_t elements[count];

  size_t j=0;
  for (size_t i=0; j<count; i++)
  {
    list_element_t e=list->elements[i];    
    bool result = (*filter)(e);
    if (result) {
      elements[j] =e;
      j++;
    }
  }

  list_t *newlist = new_list(count,elements);
  return newlist;
}

size_t length_list(list_t *list)
{
  return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
  list_element_t elements[list->length];
  for (size_t i=0; i<list->length; i++)
  {
    list_element_t e =list->elements[i];
    elements[i] = (*map)(e);
  }
  return new_list(list->length,elements);
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t))
{
  list_element_t acc = initial;
  for (size_t i=0; i<list->length; i++)
  {
    list_element_t e = list->elements[i];    
    acc = (*foldl)(acc,e);
  }
  return acc;
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t))
{
  list_element_t acc = initial;
  for (size_t i=list->length ; i>0 && list->length>0; i--)
  {
    list_element_t e = list->elements[i-1];    
    acc = (*foldr)(e,acc);
  }
  return acc;
}

list_t *reverse_list(list_t *list)
{
  size_t len = list->length; 
  list_element_t elements[len];
  for (size_t i=len, j=0; i>0 && list->length>0; i--,j++)
  {
    elements[j] =list->elements[i-1];
  }

  return new_list(len,elements);
}

void delete_list(list_t *list)
{
  free(list);
}

