#include "square_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next_col;
    struct node *next;
    int value;
} node;


square_list *create()
{
    square_list* list = malloc(sizeof(square_list));
    if (!list)
    {
        exit(1);
    }
    list->capacity = 0;
    list->size = 0;
    list->head = nullptr;

    return list;
}
void insert(int value);
void delete(int value);
void print()
{
    printf("Hello World");
}
void destroy(square_list *list)
{
    //stubbed
}