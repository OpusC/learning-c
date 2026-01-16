#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char * data;
    struct node * next;
} node;

struct linked_list
{
    node * head;
    int size;
};

linked_list * create(char * data)
{
    linked_list * list = malloc(sizeof(linked_list));
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    list->head = newNode;
    list->size = 1;
    return list;
}

void add(linked_list * list, char * data)
{
    node * slider = list->head;
    while (slider->next != NULL)
    {
        slider = slider->next;
    }
    slider->next = malloc(sizeof(node));
    slider->next->data = data;
    list->size++;
}

void removeLastElement(linked_list * list)
{
    if (list->size == 0)
    {
        return;
    }

    else if (list->size == 1)
    {
        free(list->head);
        list->head = NULL;
        list->size--;
        return;
    }

    node * slider = list->head;
    while (slider->next->next != NULL)
    {
        slider = slider->next;
    }
    free(slider->next);
    slider->next = NULL;
    list->size--;
}

void printAllElements(linked_list * list)
{
    node * slider = list->head;
    while (slider != NULL)
    {
        printf("╔══════════════╗\n");
        printf("║%s║\n", slider->data);
        printf("╚══════════════╝\n");
        printf("       ⇓        \n");
        slider = slider->next;
    }
    printf("════════════════\n");
}