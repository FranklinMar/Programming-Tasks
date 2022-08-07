/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Function my_gets(), demonstrated in lecture 
  example, can have pointer as parameter instead of array 
  for getting rid of "i" variable.
  Write a program, where you implement such an example.
------------------------------------------------------------
*/

#include <stdio.h>

char *my_gets(char *word){
	*word = getchar();
	do {
		*++word = getchar();
		
	} while (*(word) != '\n' && *(word) != '\0');
	if (*(word) == '\n')
		*(word) = '\0';
	return word;
}

int main(void){
	char word[20];
	printf("Enter a word:");
	my_gets(word);
	printf("\nWord:%s", word);
	return 0;
}
