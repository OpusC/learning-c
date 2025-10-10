#include <stdio.h>
int main() {
	int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("writing to index 9 (within bounds)\n");
	nums[9] = 1;

	printf("writing to index 10\n");
	nums[10] = 1;

	printf("writing to index 11\n");
	nums[11] = 1;

	printf("writing to index 12\n");
	nums[12] = 1;


	printf("writing to index 13\n");
	nums[13] = 1;

	printf("writing to index 9001\n");
	nums[9001] = 1;

	return 0;
}
