#include "string.h"

int main() {

	String* string1 = string_create("head_first_c");
	String* string2 = string_create("Desiging Data Intensive Applications");

	String* new_string = string_concat(string1, string2);

	string_print(string1);
	string_print(string2);
	string_print(new_string);

	return 0;
}
