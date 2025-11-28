#include <stdio.h>

struct fish
{
    char* name;
    char* species;
    int teeth;
    int age;
};

int main()
{
    struct fish snappy = {"Snappy", "piranha", 69, 4};
    printf("The fish's name is: %s", snappy.name);
    snappy.age = snappy.age + 1;
    return 0;
}