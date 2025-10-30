#include <stddef.h>
#include <stdio.h>
int main() {
	FILE* fp = fopen("sample.txt", "r"); // What is the type FILE?
	// we don't really care, we just use the exposed functions that act on it
	// it's actually implementation dependent (depends on the C library implementation)
	// GNU libc, MSVC (windows), or musl (linux but lightweight, used in Alpine Linus) might all define FILE differently
	
	if (fp == NULL) {
		perror("Error opening file"); // this will automatically print a more detailed error message
		return 1;
	}

	char buffer[5];

	size_t bytes_read = fread(buffer, 1, 4, fp); // read at most 4 bytes
	buffer[bytes_read] = '\0'; // null terminate the string
	
	printf("%s\n", buffer);

	fclose(fp);
	return 0;
}
