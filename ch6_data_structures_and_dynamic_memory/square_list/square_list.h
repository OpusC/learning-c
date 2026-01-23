#ifndef LEARNING_C_SQUARE_LIST_H
#define LEARNING_C_SQUARE_LIST_H

typedef struct node node;

typedef struct square_list
{
    unsigned int size;
    unsigned int capacity;
    node *head;
}square_list;

square_list *create();
void insert(int value);
void delete(int value);
void print();
void destroy(square_list *list);

#endif //LEARNING_C_SQUARE_LIST_H