#include <stdlib.h>
#include <stdio.h>
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
  new_node->prev = NULL;
  new_node->next = NULL;
  new_node->data = item_data;

  if (list->first == NULL) {
    list->first = new_node;
    list->last = new_node;
  }else {
    struct list_node *last_node = list->last;
    last_node->next = new_node;
    new_node->prev = last_node;
    list->last = new_node;
  }
}

ll_data_t list_pop(struct list *list){
  struct list_node *last_node = list->last;
  ll_data_t data = last_node->data;
  if (last_node->prev !=NULL) {
    struct list_node *prev_node = last_node->prev;
    list->last = prev_node;
    last_node->prev = NULL;
    last_node->next = NULL;
  }else {
    list->first = NULL;
    list->last = NULL;
  }
  return data;
}

void list_unshift(struct list *list, ll_data_t item_data){
  struct list_node *new_node = calloc(1, sizeof (struct list_node));
  struct list_node *first_node = list->first;
  new_node->prev = NULL;
  new_node->next = first_node;
  new_node->data = item_data;
  list->first = new_node;
}

ll_data_t list_shift(struct list *list){
  struct list_node *first_node = list->first;
  ll_data_t data = first_node->data;
  struct list_node *next_node = first_node->next;
  list->first = next_node;
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
      struct list_node *prev_node = node->prev;
      struct list_node *next_node = node->next;
      prev_node->next = next_node;
      next_node->prev = prev_node;
      node->next = NULL;
      node->prev = NULL;
      return;
    }
    node = node->next;
  }
}

void list_destroy(struct list *list){
  if(list == NULL) {
  }
}

