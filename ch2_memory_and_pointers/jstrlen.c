#include <stdio.h>
#include <string.h>

// A simple implementation of the strlen function in c
int jstrlen(char *str) {

  int counter = 0;

  printf("sizeof msg in jstrlen after pointer decay: %lu\n", sizeof(str));
  
  printf("strlen: %lu\n", strlen(str));

  while (*str != '\0') {
    counter++;
    str++;
  }

  return counter;
}

int main() {

  char msg[] = "123456789";

  printf("sizeof msg: %zu\n", sizeof(msg));

  printf("strlen of msg: %zu\n", strlen(msg));

  printf("jstrlen of msg: %d\n", jstrlen(msg));

  return 0;
}
