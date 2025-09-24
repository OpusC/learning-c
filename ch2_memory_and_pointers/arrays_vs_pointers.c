#include <stdio.h>

void printSizeofArray(int nums[]) {
	printf("sizeof int array in a function after pointer decay: %zu\n", sizeof(nums));
}

int main() {
	// This c code demonstrates the properties of arrays and how they are similar to pointers
	// It also demonstrates the differences to pointers
	// It will also demonstrate "pointer decay" when an array is passed into a function

	// zu is the placeholder to print the result of sizeof
	printf("sizeof(int): %zu\n", sizeof(int));
	/* an integer is commonly 4 bytes, but the c standard
	* only specifies it must be at least 16 bits (2 bytes)
	* although it says this indirectly, it just says it must be able to represent at least
	* the range −32767 to +32767
	* Here is an unofficial version of the c standard, because apparently
	* the ISO C standard (ISO/IEC 9899) is actually closed source and you have to pay to view it
	* https://c0x.shape-of-code.com/5.2.4.2.1.html
	*/

	// The result of the sizeof operator used on a pointer is the how many bytes are in a pointer
	// this is 8 on 64 bit architecture
	int *numsPointer;
	printf("sizeof called on int *: %zu\n", sizeof(numsPointer));

	int nums[5] = {1, 2, 3, 7, 5};

	/* will print the result of sizeof(int) * 5 
	* this is one of the difference between pointers and arrays in c
	* a pointer does not contain information about the length, so the compiler is unable
	* to perform the calculation to get the total size in bytes of the entire "array"
	*/
	printf("sizeof called on int array: %zu\n", sizeof(nums)); 

	// Here is a function call to demonstrate pointer decay
	printSizeofArray(nums);
	
	// using array index to access element 3 of the array
	printf("%d\n", 3[nums]);
	printf("%d\n", nums[3]);

	// using pointer arithmetic to access element 3 of the array
	printf("%d\n", *(3 + nums) );
	printf("%d\n", *(nums + 3));

}
