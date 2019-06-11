#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXCHAR 255
#define LINESIZE 128

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage:%s input_files\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	else if (argc == 2) {
		FILE *input_files = fopen(argv[1], "r");
		if (input_files == NULL) {
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		else {
			printf("Please enter the key you want to use: \n");
			int key;
			scanf("%d", &key);
			FILE *output_files = fopen("ciphertext.txt", "w");
			char line[LINESIZE];
			while(fgets(line, sizeof(line), input_files) != NULL) {
				int ch;
				for(int i = 0; i < LINESIZE; ++i) {
					ch = line[i];
					if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
						char cipher_ch;
						if (ch >= 65 && ch <= 90) {
							cipher_ch = (ch + key - 65) % 26 + 65;
						}

						else if (ch >= 97 && ch <= 122) {
							cipher_ch = (ch + key - 97) % 26 + 97;
						}
						

						line[i] = cipher_ch;
					}
						
						//printf("the cipher_ch is: %c\n", cipher_ch);
				}

				fputs(line, output_files);
				//fputs("|*\n", stdout);
			}

			fclose(input_files);
			fclose(output_files);
		}
	}

	else {
		printf("Usage:%s input_files\n", argv[0]);
		exit(EXIT_FAILURE);
	}

}