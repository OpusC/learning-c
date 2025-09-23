#include <stdio.h>
#include <string.h>
void asdfas(char msg[]) {
  printf("in function sizeof(msg) %lu\n", sizeof(msg)); // 4 + 1

}

int main() {
  char msg[] = "asdfjasdkl;fjasdklfjasdklfjasdlkfjaskl"; //23
  char msg2[] = "asdf"; //23

  char* msg3 = "asdf";

  printf("sizeof(msg) %lu\n", sizeof(msg)); // 38 + 1
  printf("sizeof(msg2) %lu\n", sizeof(msg2)); // 4 + 1
  printf("sizeof(msg3) %lu\n", sizeof(msg3)); // 4 + 1

  printf("strlen(msg) %lu\n", strlen(msg)); // 38
}
