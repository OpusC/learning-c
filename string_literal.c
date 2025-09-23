#include <stdio.h>
#include <stdlib.h>

int main() {
	// char *str = "hello";
	// printf("%s\n", str);
	// str[0] = 'z';
	// printf("%s\n", str);

	char str1[] = {'a', 'b', 'c', 'd'};
	char *str;
	str = malloc(sizeof(char) * 4);

	char *aaa;

	str = aaa;

	free(str);

	printf("%s\n", str1);

	str1[0] = 'z';

	printf("%s\n", str1);

	return 0;
}
