#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048
int main(int argc, char *argv[]) {
	int show_newline = 0;

	int opt;
	while((opt = getopt(argc, argv, "F")) != -1) {
		switch (opt) {
			case 'F':
				show_newline = 1; break;
			default:
				return 1;
		}
	}



	for (int i = optind; i < argc; i++) {
		char * file_path = argv[i];

		FILE * fp;

		fp = fopen(file_path, "r");

	if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}

		char buffer[BUFFER_SIZE];

		while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
			char *pos_newline = strchr(buffer, '\n');

			if (show_newline) {
				*pos_newline = '$';
			} else {
				*pos_newline = '\0';
			}

			printf("%s\n", buffer);
		}

		if (fclose(fp) != 0) {
			perror(NULL);
			exit(1);
		} 
	}


	return 0;

}
