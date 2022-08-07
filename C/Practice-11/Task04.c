/*
----------------
Name: Task04.c
------------------------------------------------------------
Description: Create and write your own function, that will 
  recieve N characters as parameter (including "blanks, new-
  -lines & tabs") and will store those characters in the 
  array, address of which is passed as a parameter (argument).
------------------------------------------------------------
*/
#include <stdio.h>
void getsen(char *string, int n) {
	for (int i = 0; i < n; i++) {
		*(string + i) = getchar();
	}
	*(string + n) = '\0';
}
int main(void) {
	int n;
	printf("Enter the length of sentence:");
	scanf("%d", &n);
	char string[n + 1];
	printf("Enter the sentence length of which is %d:", n);
	getsen(string, n + 1);
	printf("%s", string);
	return 0;
}
