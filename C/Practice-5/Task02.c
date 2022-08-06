/*
--------------
Name: Task02.c
--------------
Description: Write a program, that prints
string by every character with a loop.
--------------
*/
#include <stdio.h>

int main(void){
	char a[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	for (int i = 0; i < sizeof(a); i++) {
		putchar(a[i]);
	}
	return 0;
}
