#include "square_list.c"
#include "square_list.h"
#include <assert.h>
#include <stdio.h>

void testInsert() {
  square_list_ptr list = create();

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
  square_list_ptr list = create();

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

void should_insert_before_list_to_keep_sorted_order() {
  square_list_ptr list = create();

  insert(list, 2);
  insert(list, 1);

  assert(list->head->value == 1);
  assert(list->head->next->value == 2);
}

void should_set_head_to_nullptr_if_removed() {
  square_list_ptr list = create();
  insert(list, 1);
  square_list_remove(list, 1);

  assert(list->head == nullptr);
}

void should_insert_in_sorted_order() {
  square_list_ptr list = create();
  insert(list, 3);
  insert(list, 5);
  insert(list, 4);
  assert(list->head->value == 3);
  assert(list->head->next->value == 4);
  assert(list->head->next->next->value == 5);
}

void should_set_head_if_head_is_removed() {
  square_list_ptr list = create();
  insert(list, 3);
  insert(list, 4);
  square_list_remove(list, 3);
  assert(list->head != nullptr);
  assert(list->head->value == 3);
}

int main() {
  testInsert();
  testsquare_list_remove();
  should_set_head_to_nullptr_if_removed();
  should_insert_in_sorted_order();
  should_insert_before_list_to_keep_sorted_order();
  should_set_head_if_head_is_removed();
}
