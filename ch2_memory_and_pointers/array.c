#include <stdio.h>
#include <stdlib.h>
int main() {


	int value = rand();
	value = value % 20000;

	printf("value: %d\n", value);

	int *arr;
	arr = malloc(sizeof(int) * value);

	arr[0] = 0;

	// printf("%d\n", arr[0]);

	for (int i = 0; i < value; i++) {
		printf("%d\n", arr[i]);
	}

	// arr[value-1] = 99;
	// printf("arr[value - 1]: %d\n", arr[value - 1]);
}
