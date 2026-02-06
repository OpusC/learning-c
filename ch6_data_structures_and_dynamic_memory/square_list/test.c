#include "square_list.h"
#include <assert.h>
#include <stdio.h>

void testInsert() {
  square_list *list = create();

  insert(list, 1);
  assert(list->size == 1);
  assert(list->capacity == 1);

  insert(list, 2);
  insert(list, 3);
  insert(list, 4);

  assert(list->size == 4);
  assert(list->capacity == 4);

  insert(list, 5);
  assert(list->size == 5);
  assert(list->capacity == 9);

  destroy(list);
  printf("testInsert has passed\n");
}

void testsquare_list_remove() {
  square_list *list = create();

  insert(list, 1);
  assert(list->size == 1);

  square_list_remove(list, 1);
  assert(list->size == 0);

  insert(list, 1);
  insert(list, 2);
  insert(list, 3);
  insert(list, 4);
  insert(list, 5);
  assert(list->size == 5);
  square_list_remove(list, 5);
  assert(list->size == 4);

  square_list_remove(list, 5);
  printf("testSquareListRemove has passed\n");
}

int main() {

  testInsert();
  testsquare_list_remove();
}
