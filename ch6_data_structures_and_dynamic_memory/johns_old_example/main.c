#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct node {
    struct node * next;
} node_t;

void push(node_t * head) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* adding a new node */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->next = NULL;
}

// this will cause a structural error, looping the last node to a specified
// node on the list (loopNode) to simulate a structural error
void createError(node_t * head, int loopNode) {
    node_t * current = head;
    node_t * previousNode = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* causing an unexpected structural error */
    for(int i = loopNode; i > 0; i--){
        previousNode = previousNode->next;
    }
    current->next = previousNode;
}

bool correctnessVerification(node_t * head){
    node_t * current = head;
    int count = 0;
    int countDown = 1;
    node_t * compare = current;

    while (current != NULL) {
        if(countDown == 0) {
            countDown = count;
            compare = current;
            printf("countDown = %d,  count = %d\n", countDown, count);
        }
        current = current->next;
        printf("comparing %p to %p\n", compare, current);
        if(compare == current){
            return false;
        }
        count++;
        countDown--;
    }
    return true;
}

int main() {
    node_t * linkedList1 = NULL;
    linkedList1 = (node_t *) malloc(sizeof(node_t));
    if (linkedList1 == NULL) {
        return 1;
    }

    for(int i = 0; i < 4; i++){
        push(linkedList1);
    }
    createError(linkedList1, 0);

    if(correctnessVerification(linkedList1)){
        printf("The linked list is consistant\n");
        return 0;
    }
    else {
        printf("The linked list is broken\n");
        return 1;
    }
}