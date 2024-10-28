#include <stdlib.h>
#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void){
  struct list *l = calloc(1,sizeof(struct list));
  return l;
}

size_t list_count(const struct list *list){
  size_t count =0;
  if (list->first == NULL)
    return count;
  count++;
  if (list->first == list->last)
    return count;
  struct list_node *node = list->first;
  while (node->next !=NULL) {
    count++;
    node = node->next;
  }
  return count;
}

void list_push(struct list *list, ll_data_t item_data){
  struct list_node *new_node = calloc(1, sizeof (struct list_node));
  new_node->data = item_data;

  if (list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
  }else {
    list->last->next = new_node;
    new_node->prev = list->last;
    list->last = new_node;
  }
}

ll_data_t list_pop(struct list *list){
  struct list_node *last_node = list->last;
  ll_data_t data = last_node->data;
  if (last_node->prev !=NULL) {
    list->last = last_node->prev;
  }else {
    list->first = NULL;
    list->last = NULL;
  }
  free(last_node);
  last_node = NULL;
  return data;
}

void list_unshift(struct list *list, ll_data_t item_data){
  struct list_node *new_node = calloc(1, sizeof (struct list_node));
  new_node->next = list->first;
  new_node->data = item_data;
  list->first = new_node;
}

ll_data_t list_shift(struct list *list){
  struct list_node *first_node = list->first;
  ll_data_t data = first_node->data;
  list->first = first_node->next;
  free(first_node);
  first_node = NULL;
  return data;
}

void list_delete(struct list *list, ll_data_t data){
  struct list_node *node = list->first;
  if (node->data == data) {
    list_shift(list);
    return;
  }

  if (list->last->data == data) {
    list_pop(list);
    return;
  }

  while (node->next) {
    if (node->data == data) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      free(node);
      node = NULL;
      return;
    }
    node = node->next;
  }
}

void list_destroy(struct list *list){
  free(list);
}

