/*
----------------
Name: Task06.c
------------------------------------------------------------
Description: Write a program, that will read line (string) 
  array (array of char's) from user input. Create a function, 
  that will read first word from every line (string), and 
  will write this word into array, and ignore all further 
  words. Also, the function must read all lines (strings) 
  of array on input, regardless of their amount, but save 
  only the first words, and destroy the rest in each line. 
  For ease of completing the task, think of word as a char 
  sequence, separated by whitespaces.
------------------------------------------------------------
*/
#include <stdio.h>

int getsen(char *string, int n, int *f) {
	int e = 1;
	for (int i = 0; i < n; i++) {
		*(string + i) = getchar();
		if (*(string + i) == '\n') {
			*(f + e) = i + 1;
			e++;
		}
	}
	*(string + n) = '\0';
	return e;
}

void str(char *string, int n, int e, int *f) {
	char word[50];
	int l = 1;
	for (int j = 0, k = 0; j < e; j++) {
		l = 1;
		for (int i = *(f + j); i < n && l == 1; i++) {
			if (*(string + i) == '\n' || *(string + i) == ' ' || *(string + i) == '\t') {
				*(word + k) = ' ';
				l = 0;
			} else {
				*(word + k) = *(string + i);
			}
			k++;
		}
	}
	for (int i = 0; i < n; i++) {
		*(string + i) = *(word + i);
	}
	*(string + n) = '\0';
}

int main(void) {
	char string[50];
	printf("Enter lines of words:\n");
	int newline[50];
	newline[0] = 0;
	int new = getsen(string, 50, newline);
	str(string, 50, new, newline);
	printf("The words are:%s", string);
	return 0;
}
