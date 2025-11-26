#include "string.h"

int main() {

	String a = string_create("head_first_c");
	String b = string_create("Desiging Data Intensive Applications");

	String new_string = string_concat(a, b);

	string_print(a);
	string_print(b);
	string_print(new_string);

	return 0;
}
