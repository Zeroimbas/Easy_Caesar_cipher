The encrypt.c and decrypt.c files are C programs written on OS: Ubuntu 18.04.2 LTS. The programs are tested on the same OS. The usage on any other OS is not tested.

System requirement: A Ubuntu 18.04.2 LTS with 'sudo gcc' installed.

Usage:
	In the terminal, type or copy & paste the following command with changing the name of 'input_files.txt' to the name of the text file you want to encrypt/decrypt.
	
	sudo gcc -o encrypt encrypt.c
	sudo ./encrypt input_files.txt (Any text file provide by the user).
	sudo gcc -o decrypt decrypt.c
	sudo ./decrypt input_files.txt (Any text file provide by the user).

Result:
	The encrypt program will generate encrypted text file based on the input_file, the generated file name is 'ciphertext.txt' and the encrypted text will be written into it.

	The decrypt program will generate decrypted text file based on the input_file, the generated file name is 'plaintext.txt' and the decrypted text will be written into it.


