#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
/*
* Ask the user for text they are looking for
* Loop through all of the track names
* If a track name contains the text search, display the track name
*/


/*
* string.h functions:
* strchr(): Find the location of a character inside a string
* strcmp(): Compare two strings
* strstr(): Find the location of a string inside another string
* strcpy(): Copy one string to another
* strlen(): Find the length of a string
* strcat(): Concatenate two strings
*/
#include <stdio.h>

void replace_newline_with_null_terminator(char *str)
{
	if (strchr(str, '\n'))
	{
		str[strcspn(str, "\n")] = '\0';
	}
}

int main() {

	char tracks[][80] = {
		"I left my heart in the Mastercard Office",
		"Pune, Pune - a wonderful town",
		"Dancing with IBM ODM RULES ENGINE",
		"From Toronto to the Vancouver Office",
		"The com.ibm.rules.res.xu exception from the Rules Engine",
	};

	printf("Search for text in the track you are looking for: ");

	char input[80];
	// Note: Strings require a null byte at the end, so we can only accept
	// 80 - 1 as input to ensure we can put the null byte at the end
	// also scanf bla bla bla stops reading at the first whitespace so we can't use it
	// scanf("%79s", input);
	
	// Note: fgets is usually preferred because the length of input is a required argument
	// Also fgets is meant for strings so you can use 80 as the argument value, the size
	// provided is the size of the buffer so it will need be the length of the input + 1
	// fgets(input, 80, stdin)
	fgets(input, 80, stdin);

	replace_newline_with_null_terminator(input);

	/*
		* strstr https://en.cppreference.com/w/c/string/byte/strstr
		* Parameters:
		* str - pointer to the null-terminated byte string to examine
		* substr - pointer to the null-terminated byte string to search for
		*
		* Return Value:
		* pointer to the first character of the found substring in str, or a null pointer
		* if such substring is not found. If substr points to an empty string, str is returned
		*
	*/

	int found_match = FALSE;

	if (strlen(input) == 0)
	{
		printf("You must enter a search term\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 5; i++) {
		char* res = strstr(tracks[i], input);
		if (res != NULL) {
			printf("%s was found at index %u\n", tracks[i], i);
			found_match = TRUE;

		}
	}

	if (found_match) {
		exit(EXIT_SUCCESS);
	}

	printf("No results were found\n");

}
