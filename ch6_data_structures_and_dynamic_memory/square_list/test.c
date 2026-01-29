#include "square_list.h"
#include <assert.h>
#include <stdio.h>

void testInsert() {
    square_list *list = create();
    
    insert(list, 1);
    assert(list->size == 1);
    assert(list->capacity == 4);

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

void testDelete() {
    square_list *list = create();

    insert(list, 1);
    assert(list->size == 1);

    delete(list, 1);
    assert(list->size == 0);

    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    assert(list->size == 5);
    delete(list, 5);
    assert(list->size == 4);

    delete(list);
    printf("testInsert has passed\n");

}

int main() {

    testInsert();
    testDelete();

}
