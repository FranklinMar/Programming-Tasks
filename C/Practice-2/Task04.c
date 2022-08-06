/*
--------------
Name: Task04.c
--------------
Description: Write a program, that formats a string with string
variable and 2 float variables, then prints them into the console.
--------------
*/
#include <stdio.h>
#define BOOK "Kobzar"
int main(){
	float cost = 9.49;
	float percent = 80.0;
	printf("This copy of %s sells for %.2f\n", BOOK, cost);
	printf("That is %2.f %% of list",percent);
	return 0;
}
