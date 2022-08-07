

/*
----------------
Name: Task02A.c
------------------------------------------------------------
Description: Write a program, that will complete next tasks 
  with pointers:
  
- Read a few words from user input (consider checks to make 
  it impossible to enter numbers or other symbols);
- Print words in sorted alphabetical order into the console 
  (you may use only latin characters and letters).
------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#define W 10

//Test string - "h3el4loпривіт T-!@h%e##re"

int main(void){
	char string[W][30];
	printf("Please enter 10 words(Press Enter):\n");
	for (int u = 0; u < W; u++) {
		gets(*(string + u));
	}
	for (int u = 0; u < W; u++) {
		for (int i = 0; string[u][i] != '\0'; ++i) {
			while (!((*(*(string + i) + u) == '\0') || 
				 ((*(*(string + i) + u) >= 'a') && ((*(*(string + i) + u) <= 'z'))) || 
				 ((*(*(string + i) + u) >= 'A') && (*(*(string + i) + u) <= 'Z')))) {
				int j;
				for (j = i; *(*(string + j) + u) != '\0'; ++j) {
					*(*(string + j) + u) = *(*(string + j + 1) + u);
				}
				*(*(string + j + 1) + u) = '\0';
			}
		}
	}
	printf("Words in given order:\n");
	for (int u = 0; u < W; u++) {
		printf("%s\n",*(string + u));
	}
	char t[30];
	for (int i = 0; i < W - 1; ++i) {
		for (int j = i + 1; j < W; ++j) {	
			if (strcmp(*(string + i), *(string + j)) > 0) {
				strcpy(t, *(string + i));
				strcpy(*(string + i), *(string + j));
				strcpy(*(string + j), t);
			}
		}
	}
	printf("Words in Alphabet order:\n");
	for(int u = 0; u < W; u++){
		printf("%s\n", string[u]);
	}
	return 0;
}
