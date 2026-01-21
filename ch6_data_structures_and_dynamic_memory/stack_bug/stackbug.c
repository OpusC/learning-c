#include <stdio.h>
char *getName() {
    char name[30];
    printf("enter name\n");
    fgets(name, sizeof(name), stdin);

}

int main() {
    char *name = getName();

    printf("name: %s\n", name);
    return 1;
}
