/*
----------------
Name: Task07.c
------------------------------------------------------------
Description: Write a program, in which implement function, 
  that will get char line (string) as input from user, and 
  will print out on console this line in reverse order. 
  Input data into the function must be passed with loops.
------------------------------------------------------------
*/
#include <stdio.h>

void reverse() {
	char s[50];
	int i = 0;
	while((s[i++] = getchar() ) != '\n' && i < 50);
	--i;
	while(i >= 0){
		putchar(s[i]);
		i--;
	}
}

int main(void) {
	printf("Enter the sentence:");
	reverse();
	return 0;
}
