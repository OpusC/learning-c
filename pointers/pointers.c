#include <stdio.h>

const int variable = 5;

void add5(int *pa) {
  *pa += 5;
  // print out hex value of a
  printf("value of &pa: %p\n", &pa);
  printf("value of pa: %p\n", pa);

}

int main() {

  int a = 5; // &a = 0x40

  printf("value of &a: %p\n", &a);
  // print out hex value of &a

  printf("%d\n", a); // 5

  add5(&a); // 0x40

  printf("%d\n", a); // 10

  return 0;

}
