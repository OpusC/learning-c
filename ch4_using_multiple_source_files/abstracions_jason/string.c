#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
	char* data;
	int length;
} String;

String* string_create(const char* string) {
	size_t size = strlen(string); // does NOT consider the null byte at the end of the string for the return size

	char* data = malloc(size);
	memcpy(data, string, size);

	String* new_string = malloc(sizeof(String));

	new_string->data = data;
	new_string->length = size;

	return new_string;
}

int string_length(const String* string) {
	return string->length;
}


String* string_concat(const String* string_1, const String* string_2) {
	int new_length = string_1->length + string_2->length;

	char* new_data = malloc((size_t) new_length);
	memcpy(new_data, string_1, (size_t) string_1->length);
	memcpy(new_data + string_1->length, string_2, string_2->length);
	
	String* new_string = malloc(sizeof(String));

	new_string->data = new_data;
	new_string->length = new_length;

	return new_string;
}

void string_print(const String* s) {
	printf("%.*s\n", s->length, s->data);
}
