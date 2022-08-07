/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Write a program, that read 2 variables from 
  user input, then compare them and prints the appropriate 
  message to the console.
  
  All of this should repeat several times.
  Use ?: operator instead of if...else .
------------------------------------------------------------
*/
#include <stdio.h>

int main(void){
	double a;
	double b;
	printf("Enter symbols 'a' and 'b' to compare them(q to quit)\n");
	printf("a:");
	while( (scanf("%lf", &a)) != 0 ){
		printf("b:");
		scanf("%lf", &b);
		a > b ? printf("a is bigger than b (a>b)\n") : a < b ? printf("b is bigger than a (a<b)\n") : printf("a is equal b (a=b)\n");
		getchar();
		printf("Enter symbols 'a' and 'b' to compare them(q to quit)\n");
		printf("a:");
	}
	return 0;
}
