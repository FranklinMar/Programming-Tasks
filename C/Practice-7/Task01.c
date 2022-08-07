/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: Write a program, that will encrypt a string,
which is read from the user input, by Ceasar's cipher and
print it out on the console.
------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define S 18
#define a 30

// Encrypt the string by Ceasar's cipher
char cipher(char w[S]);

int main (void){
	char word[S];
	int I = 1;
	printf("Please enter the word to encrypt it:\n");
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++) {
		// If not an alphabet character
		if (!islower(word[i]) && !isupper(word[i])) {
			I = 0;
		}
	}
	if (I) {
		cipher(word);
		printf("Encrypted word:%s",word);
	} else {
		printf("Sorry,but you have entered wrong type of symbols.\n Please use English Alphabet letters");
	}
	return 0;
}

char cipher(char w[S]){
	for (int i = 0; i < strlen(w); i++) {
		if (w[i] >= 'x' || (w[i] >= 'X' && w[i] <= 'Z')) {
			w[i] -= 23;// ('z' - 'a') - key = 26 - Key
		} else {
			w[i] += 3;// Key
		}
	}
	return w;
}
