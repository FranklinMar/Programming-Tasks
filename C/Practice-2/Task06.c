/*
----------------
Name: Task06.c
------------------------------------------------------------
Description: With a given C program, explain what happens
  in each printf function call, and what is the result.
------------------------------------------------------------
*/
#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
int main(void){
	int num = 10;
	printf(FORMAT,FORMAT);/* At first, into the content of const FORMAT ("%s! C is cool!") instead of
		substring "%s", the content of the same const FORMAT is replaced. Result = "%s! C is cool!! C is cool!" */
	printf("%d\n",++num);// Operator ++num increased the value of 'num' variable by 1, then it's value is printed on console. num = 11.
	printf("%d\n",num++);// Operator num++ returned the value of 'num' variable to be printed on console, then increased the value by 1. num = 11
	printf("%d\n",num--);// Operator num-- returned the value of 'num' variable to be printed on console, then decreased the value by 1. num = 12
	printf("%d\n",--num);// Operator --num decreased the value of 'num' variable by 1, then it's value is printed on console. num = 10
	return 0;
}
