/*
--------------
Name: Task07.c
--------------
Description: Write a program, that demonstrates variable type
automatic conversion and dislays it on console, and explain it.
--------------
*/
#include <stdio.h>
int main(){
	char c1, c2;
	int diff;
	float num;
	c1 = 'S';
	c2 = 'O';
	diff = c1 - c2; // Compiler converts the type of 'с1' & 'с2' vars into 'int' вy ASCII number, subtracts them and saves the result in 'diff'
	num = diff; // Compiler convers the type of 'diff' var from 'int' to 'float' end stores it in 'num'
	printf("%c%c%c:%d %3.2f\n", c1, c2 ,c1, diff, num);
	return 0;
}
