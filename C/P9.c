/*
----------------
Name: Task09.c
------------------------------------------------------------
Description: Write a program, that will have a function
  strncpy(s1, s2, n), that will copy exactly n characters 
  from s2 into s1, cutting off s2 or adding null characters 
  inside it. Target string can be not null, if length of s2
  equals n, or bigger. Function must return s1. Also, write 
  your own version of function, that will perform similiar 
  to original actions; call it mystrncpy(). Test your 
  function on complete program, that will use loop to input 
  values for function.
------------------------------------------------------------
*/
#include <stdio.h>
#include <string.h>

void mystrncpy(char s1[], char s2[], int n);

int main(void) {
	char s2[52] = "I am simple man making his way through the universe"; 
	char s1[40];
	printf("Enter the numbers to copy:");
	int n;
	scanf("%d", &n);
	strncpy(s1, s2, n);
	printf("strncpy:\n%s \n%s\n", s2, s1);
	mystrncpy(s1, s2, n);
	printf("mystrncpy:\n%s \n%s", s2, s1);
	return 0;
}

void mystrncpy(char *s1, char *s2, int n) {
	int o1 = sizeof(s1);
	for (int i = 0; i < n; i++) {
		*(s1 + i) = *(s2 + i);
	}
	if (n < o1) {
		for (int i = o1 - n; i < o1; i++) {
			*(s1 + i) = '\0';
		}
	}
}
