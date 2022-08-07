/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: Write a program, that reads a string from user 
  and then prints it by every character.
------------------------------------------------------------
*/
#include <stdio.h>
#define S 16
int main(void){
	char w[S];
	printf("Please enter any few symbols:");
	gets(w);
	printf("The symbols are:");
	for(int i = 0; i < sizeof(w); i++){
		printf(" ");
		putchar(w[i]);
	}
	return 0;
}
