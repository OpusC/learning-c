#include <stdio.h>

int main(void) {
    // Recap: how to declare a struct
    struct point {
        int x;
        int y;
    };
    struct point coord = {3, 5};
    printf("x: %d y: %d\n", coord.x, coord.y);

    // Declare a person type - we'll use this as a linked list node
    typedef struct person {
        char *name;
        int age;
        struct person *next;
    } person;

    // Print the fields on the first node
    person cam = {"Cam", 83, NULL};
    printf("Meet %s age %d\n", cam.name, cam.age);
    printf("Meet %s\n", (char*)&cam); // doesn't work, wamp wamp

    // Assign the next node in the list
    person nick = { "Nick" , 42, NULL};
    cam.next = &nick;
    printf("Meet Cam's %s age %d\n", cam.next->name, cam.next->age);

    // Assign the third node in the list
    person jason = { "Jason", 21, NULL};
    nick.next = &jason;

    // Walk the entire list
    for (person *thisGuy = &cam; thisGuy != NULL;) {
        printf("This is %s\n", thisGuy->name);
        thisGuy = thisGuy->next;
    }

    return 0;
};