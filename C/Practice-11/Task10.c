/*
----------------
Name: Task10.c
------------------------------------------------------------
Description: Write a program, that will have created 
  function string_in(), that will take 2 char pointers 
  (strings) as arguments. If the second string is inside the 
  first string (is the substring of the first), the function 
  must return it's address, where the substring starts. 
  For example, the function is called with next arguments: 
  string_in("hats, "at"), and returns address at the 
  character "a" from the first string. If the first string 
  is the substring of the second, function must return NULL 
  pointer. Create the program in that way, that for passing 
  input values for function, the loops were involved. Don't 
  forget to make checks on correct input.
------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>

char* string_in(char s1[], char s2[], int w1, int w2);
void my_gets(char *word);

int main(void) {
	char s1[20];
	char s2[20];
	printf("Please enter string #1:");
	my_gets(s1);
	printf("\nPlease enter string #2:");
	my_gets(s2);
	int w1 = strlen(s1);
	int w2 = strlen(s2);
	printf("Result:%p", string_in(s1, s2, w1, w2));
	return 0;
}

void my_gets(char *word) {
	int size = sizeof(word);
	int i = 0;	
	*word = getchar();
	do {
		*(++word) = getchar();
	} while(*(word) != '\n' && *(word) != '\0' && *(word) != ' ' && (++i) < size);
	if(*(word) == '\n')
		*(word) = '\0';
}

char* string_in(char s1[], char s2[], int w1, int w2) {
	int j = 0;
	int e = 1;
	int ind;
	if (w1 >= w2) {
		for (int i = 0; i < w1; i++) {
			if (s1[i] == s2[j]) {
				if (e) {
					ind = j;
					e--;
				}
				j++;
				if (j == w2 - 1) {// If index is at the end of string
					return &s2[ind];
				}
			} else {
				j = 0;
			}
		}
	} else {
		return NULL;
	}
}
