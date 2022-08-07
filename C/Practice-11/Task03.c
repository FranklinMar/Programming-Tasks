/*
----------------
Name: Task03.c
------------------------------------------------------------
Description: Write a program, that will implement next 
  task (or solve next problem):
- Function strlen() gets pointer on string as an argument 
  and returns the length of this string.
------------------------------------------------------------
*/
#include <stdio.h>
int strlen(char *string) {
	int size = 0;
	while (*(string + size) != '\n' && *(string + size) != '\0') {
		size++;
	}
	return size;
}
int main(void) {
	char string[6] = "hello";
	printf("Size of %s = %d", string, strlen(string));
}
