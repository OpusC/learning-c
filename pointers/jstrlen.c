#include <stdio.h>
#include <string.h>

#define ODYSESSUS 0x1000000000
#define LIGHT_THEME 0x0100000000
#define WEDNESDAY 0x0010000000


a[b] = *(a + b)

int jstrlen(char *str) {

  int counter = 0;

  printf("sizeof msg in jstrlen: %lu\n", sizeof(str));
  

  printf("strlen: %lu\n", strlen(str));

  while (*str != '\0') {
    counter++;
    str++;
  }

  return counter;
}

void foo(int flag) {
  int isOdysseus = flag & ODYSESSUS;
  return;
}


void foo(type actualThing, boolean isOdysseus, boolean isLightTheme, boolean isWednesday) {
  return;
}

int main() {

  printf("sizeof int %lu\n", sizeof(int));

  char msg[] = "123456789"; // this is an array

  printf("sizeof msg: %lu\n", sizeof(msg));

  printf("strlen: %d\n", jstrlen(msg));

  foo(ODYSESSUS | LIGHT_THEME | WEDNESDAY);

  return 0;
}
