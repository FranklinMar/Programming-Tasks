/*
--------------
Name: Task02.c
--------------
Description: The same, as the Task01, except use
Vigenere's cipher for encrypting with keyword.
--------------
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define S 18
#define a 30

// Encrypt the string with Vigenere's cipher by given keyword
char cipher(char w[S], char key[S]);

int main(void){
	char word[S];
	char key[S];
	int j = 1, I = 1;
	printf("Enter the code word:");
	scanf("%s", key);
	for (int i = 0; i < strlen(key); i++)
		if(!islower(key[i]) && !isupper(key[i])) 
			j = 0;
	
	if (j) {
		printf("Please enter the word to encrypt it:");
		scanf("%s",word);
		for(int i = 0; i < strlen(word); i++)
			if(!islower(word[i]) && !isupper(word[i])) 
				I = 0;
		
		if (I) {
			cipher(word, key);
			printf("\nEncrypted word:%s", word);
		} else 
			printf("Sorry,but you have entered wrong type of symbols.\n Please use only English Alphabet letters");
	} else 
		printf("Sorry,but you have entered wrong type of symbols.\n Please use only English Alphabet letters");
	
	return 0;
}
char cipher(char w[S], char key[S]){
	//-96 + key[p % strlen(key)] = Key Formula
	int p = 0;
	int k;
	for (int i = 0; i < strlen(w); i++) {
		if (islower(key[i]))
			k = -96 + key[p % strlen(key)]; /*For small characters*/
		else if (isupper(key[i]))
			k = -64 + key[p % strlen(key)]; /*For big characters*/
		if ( (w[i] > ('z' - k) && w[i] <= 'z') || (w[i] > ('Z' - k) && w[i] <= 'Z') ) {
			w[i] -= 26 - k;
		} else {
			w[i] += k;
		}
		p++;
	}
	return w;
}
