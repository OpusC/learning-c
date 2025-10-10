#include <stdio.h>
int main() {
	int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("nums[9] (within bounds): %d\n", nums[9]);
	printf("nums[10] (within bounds): %d\n", nums[10]);
	printf("nums[11] (within bounds): %d\n", nums[11]);
	printf("nums[12] (within bounds): %d\n", nums[12]);
	printf("nums[13] (within bounds): %d\n", nums[13]);

	printf("nums[9001] (within bounds): %d\n", nums[9001]);

	return 0;
}
