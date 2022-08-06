/*
--------------
Name: Task03.c
--------------
Description: Write a program, that reads a 
string from user, then converts every character
of it to lower (if possible) and prints it on console.
--------------
*/
#include <stdio.h>
#include <ctype.h>

int main(void){
	int k = 'a' - 'A';// = 32 According to ASCII coding
	int S = 28;
	int i = 0;
	char a[S];
	printf("Enter symbols:\n");
	while( (a[i] = getchar()) != '\n' && i < sizeof(a) ){
		i++;
	}
	printf("Result:\n");
	for(int j = 0; j < i; j++){
		if (isupper(a[j])) {
			putchar(a[j]);
		} else if(a[j] >='a' && a[j] <= 'z') {// islower(a[j])
			a[j] = (int) a[j] - k;
			putchar((char) a[j]);
		} else {
			putchar(a[j]);	
		}
	}
	return 0;
}
