#include <stdio.h>
#include <string.h>
int main() {
		int zero_int = 0;
		char zero_char = '\0';

		printf("zero_int and zero_char are: ");

		// This equality is true because of Integer Promotion
		// https://wiki.sei.cmu.edu/confluence/display/c/INT02-C.%2BUnderstand%2Binteger%2Bconversion%2Brules?
		// The rules of integer promotion are important in many cases, for example:
		// 1. function calls with variadic arguments will usually promote to int. One example is printf, if you pass in a char
		// as an argument it will get promoted to an int
		// Bitwise operators: Signed char values are promoted to int before bitwise operations, so the top bit can sign-extend and give unexpected results
		// this extends to all integer types smaller than int
		// Arithmetic on mixed types: integer promotion will occur so you might get unexpected behavior
		if (zero_int == zero_char) {
				printf("equal\n");
		} else {

				printf("not equal\n");
		}

		printf("zero_int and zero_char compared with memcmp are: ");

		// Note that this compiles but we are checking memory past the bounds of char so this is undefined behavior
		// Using the below compiler flags will prevent this from compiling
		// gcc -Wall -Wextra -Werror isZeroZero.c
		if (memcmp(&zero_int, &zero_char, sizeof(int))) {
				printf("equal\n");
		} else {
				printf("not equal\n");
		}

}
