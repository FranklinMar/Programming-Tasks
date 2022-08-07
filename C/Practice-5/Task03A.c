/*
----------------
Name: Task03A.c
------------------------------------------------------------
Description: Write a program, that reads a string from user, 
  then converts every character of it to upper (if possible) 
  and prints it on console.
------------------------------------------------------------
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
		if (islower(a[j])) {
			putchar(a[j]);
		} else if (a[j] >= 'A' && a[j] <= 'Z'){// isupper(a[j])
			a[j] = (int) a[j] + k;
			putchar((char) a[j]);
		} else {
			putchar(a[j]);
		}
	}
	return 0;
}
