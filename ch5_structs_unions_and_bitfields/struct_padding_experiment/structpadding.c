#include <stddef.h>
#include <stdio.h>
int main() {
	struct a {
		char ch;
		int i;
	};

	struct b {
		int i;
		char ch;
	};

	// the offset of the int in struct a will be 4. char is 1 byte but 3 bytes are padded to make it the 
	// int memory aligned
	printf("offsets in struct a and struct b in bytes\n");
	printf("struct a\n ch: %zu\ni %zu\n", offsetof(struct a, ch), offsetof(struct a, i));

	printf("struct b\n i: %zu\nch %zu\n", offsetof(struct b, i), offsetof(struct b, ch));

	printf("\n");


	// Why is this important? Check the sizeof on this next two structs with different orders but same data types inside

	struct c {
		char ch1;
		int i;
		char ch2;
	};

	struct d {
		int i;
		char ch1;
		char ch2;
	};

	printf("sizeof c: %zu\n", sizeof(struct c));
	printf("sizeof d: %zu\n", sizeof(struct d));

	printf("\n");

	// and this extra padding accumulates a lot for an array of structs

	struct c cArray[5];
	struct d dArray[5];

	printf("sizeof cArray[5]: %zu\n", sizeof(cArray));
	printf("sizeof dArray[5]: %zu\n", sizeof(dArray));

	printf("\n");

	// different data types have different alignment rules
	struct e {
		char ch;
		double d;   // 8 bytes, needs 8-byte alignment
	};

	struct f {
		double d;   // 8 bytes
		char ch;
	};

	printf("struct e:\n");
	printf("offsetof(ch) = %zu\n", offsetof(struct e, ch));
	printf("offsetof(d)  = %zu\n", offsetof(struct e, d));
	printf("sizeof(struct e) = %zu\n", sizeof(struct e));

	printf("struct f:\n");
	printf("offsetof(d)  = %zu\n", offsetof(struct f, d));
	printf("offsetof(ch) = %zu\n", offsetof(struct f, ch));
	printf("sizeof(struct f) = %zu\n", sizeof(struct f));
}
