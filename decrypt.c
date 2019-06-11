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
			printf("Please enter the key you get: \n");
			int key;
			scanf("%d", &key);
			FILE *output_files = fopen("plaintext.txt", "w");
			char line[LINESIZE];
			while(fgets(line, sizeof(line), input_files) != NULL) {
				char cipher_ch;
				for(int i = 0; i < LINESIZE; ++i) {
					cipher_ch = line[i];
					
					//char plain_ch;
					if (cipher_ch >= 'a' && cipher_ch <= 'z') {
						cipher_ch = cipher_ch - key;
						if (cipher_ch < 'a') {
							cipher_ch = cipher_ch + 'z' - 'a' + 1;
						}

						line[i] = cipher_ch;
					}

					else if (cipher_ch >= 'A' && cipher_ch <= 'Z') {
						cipher_ch = cipher_ch - key;
						if (cipher_ch < 'A') {
							cipher_ch = cipher_ch + 'Z' - 'A' + 1;
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