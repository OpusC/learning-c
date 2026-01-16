#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    char *name;
    int age;
} person;

typedef struct personNode
{
    person this;
    struct personNode *next;
} personNode;

char *getName()
{
    char *name = malloc(sizeof(char) * 100);
    if (name == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for name");
        exit(1);
    }
    printf("MY GRANDMA IS BEING CRUSHED BY A SERVER. PLEASE ENTER A PERSON'S NAME SO SHE CAN BE SAVED:\n");
    fgets(name, sizeof(name), stdin);
    return name;
}

int getAge()
{
    char buffer[12];
    printf("Please enter their age:\n");
    fgets(buffer, sizeof(buffer), stdin);
    int age = strtol(buffer, nullptr, 10);
    return age;
}

person *buildPerson()
{
    char *personsName = getName();
    int age = getAge();
    person *aPerson = malloc(sizeof(person));
    if (aPerson == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for person");
        exit(1);
    }
    aPerson->name = personsName;
    aPerson->age = age;
    printf("You have created a person with the name %s and age %d\n", aPerson->name, aPerson->age);
    return aPerson;
}

int main(void) {
    // Declare a person type - we'll use this as a linked list node
    char input = ' ';

    while (input != 'Q')
    {
        person *newPerson = buildPerson();
        printf("Add another person? (Y)es, (N)o, (Q)uit\n");
        input = (char) fgetc(stdin);
        fgetc(stdin); // this is a horrible hacky solution!!!!!!!!!!!
    }
    return 0;
};