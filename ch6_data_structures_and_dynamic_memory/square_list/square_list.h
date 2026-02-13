#ifndef LEARNING_C_SQUARE_LIST_H
#define LEARNING_C_SQUARE_LIST_H

// typedef struct node node;
typedef struct node {
    struct node *next_col;
    struct node *next;
    int value;
} node;

typedef struct Square_list
{
    unsigned int size;
    unsigned int capacity;
    node *head;
    node *tail;
} square_list, *square_list_ptr;

square_list_ptr create();
void insert(square_list_ptr list, int value);
void square_list_remove(square_list_ptr list, int value);
void print(square_list_ptr list);
void destroy(square_list_ptr list);

#endif //LEARNING_C_SQUARE_LIST_H
