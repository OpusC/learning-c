#include <stdio.h>

const int variable = 5;

void add5(int *pa) {
  *pa += 5;

  // pa is a stack variable created with the call of this function
  // it will have its own address on the stack
  printf("value of &pa: %p\n", &pa);
  // the value of pa is equivalent to &a because it is a pointer to a
  printf("value of pa: %p\n", pa);

  printf("exiting add5\n");
}

int main() {

  // The address of a is available to see here with &a
  // I mark is as 0x40 for simplicity in comments although it will
  // be different at runtime
  int a = 5; // &a = 0x40

  // print out hex value of &a, the address of the integer variable a
  printf("value of &a: %p\n", &a);

  // print out the value of a itself
  printf("value of a: %d\n", a); // 5

  printf("passing in &a to the function add5\n");
  add5(&a); // 0x40

  printf("value of a: %d\n", a); // 10

  return 0;

}
