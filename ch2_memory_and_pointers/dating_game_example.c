#include <stdio.h>

int main()
{
    int contestants[] = {1, 2, 3};
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    /* How this works:
     * Because contestants[2] is now equal to *choice
     * and *choice is equal to the first memory address
     * of contestants; aka contestants[0], we get 2 as the answer.
     */
    printf("I'm going to pick contestant number: %i\n", contestants[2]);
    return 0;
}