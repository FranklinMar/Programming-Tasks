/*
--------------
Name: Task04.c
--------------
Description: Write a program, that reads 
a character from user, and checks if it is space, alphabetic, 
or non-alphabet character, then prints to the console.
--------------
*/
#include <stdio.h>
#include <ctype.h>

int main(void){
	printf("Enter symbol:\n");
	char a = getchar();
	if (isalpha(a)) {
		printf("%c is an alphabet",a);
	} else if(isspace(a)) {
		printf("SPACE was entered");
	} else {
		printf("%c is not an alphabet",a);
	}
	return 0;
}
