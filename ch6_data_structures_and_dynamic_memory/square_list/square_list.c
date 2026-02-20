#include "square_list.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct node {
//   struct node *next_col;
//   struct node *next;
//   int value;
// } node;

node *create_node(int value) {
  node *n = malloc(sizeof(node));
  if (!n) {
    exit(EXIT_FAILURE);
  }

  n->value = value;
  n->next = nullptr;
  n->next_col = nullptr;

  return n;
}

square_list_ptr create() {
  square_list_ptr list = malloc(sizeof(square_list));
  if (!list) {
    exit(1);
  }
  list->capacity = 0;
  list->size = 0;
  list->head = nullptr;
  list->tail = nullptr;

  return list;
}

void insert(square_list_ptr list, int value) {
  node *n = create_node(value);
  if (!list->head) {
    list->head = n;
  } else {
    //insert sorted
    node *curr = list->head;
    node *prev = list->head;
    while (curr != nullptr)
    {
      if (curr->value > value)
      {
        n->next = curr;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    if(value < list->head->value)
    {
      list->head = n;
    }
    if (curr == nullptr)
    {
      list->tail = n;
    }
    prev->next = n;
  }
  

  // list->tail = n;
  list->size++;
  list->capacity = pow(ceil(sqrt(list->size)), 2);
}

void square_list_remove(square_list_ptr list, int value) {
  node *curr = list->head;
  node *prev = list->head;

  while (curr != nullptr) {
    if (curr->value == value) {
      prev->next = curr->next;
      if (list->head->value == value)
      {
        list->head = list->head->next;
      }
      free(curr);
      list->size--;
      return;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}
void print(square_list_ptr list)
{
  (void) list;
  printf("Hello World");
}
void destroy(square_list_ptr list) {
  printf("We got %d", list->head->value);
  // stubbed
}
