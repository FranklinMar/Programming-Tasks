/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Write a program, that complete next tasks with 
  pointers:
  
- Get a sentence from user input with letters and symbols;
- Delete symbols from a string, leaving only spaces and 
  alphabetic characters.
------------------------------------------------------------
*/
#include <stdio.h>

int main (void) {
	char string[30];
	char *ptr = &string[0];
	int i = 0;
	printf("Enter the sentence of 30 symbols and letters:");
	while ( (*(ptr + i) = getchar()) != '\n' && i < 30) {
		i++;
	}
	for(i = 0; *(ptr + i) != '\0'; ++i){
		while(!((*(ptr + i) == '\0') || (*(ptr + i) == ' ') || 
			((*(ptr + i) >= 'a') && (*(ptr + i) <= 'z')) || 
			((*(ptr + i) >= 'A') && (*(ptr + i) <= 'Z')))) {
			int j;
			for(j = i; *(ptr + j) != '\0'; ++j){
				*(ptr + j) = *(ptr + j + 1);
			}
			*(ptr + j)='\0';
		}
	}
	printf("\nSentence:");
	printf("%s",string);
	return 0;
}
