/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Write a program, that uses 'for' loop and 
  prints out the result.
------------------------------------------------------------
*/
#include <stdio.h>
int main(void){
	int value;
	for(value = 36; value > 0; value /= 2){
		printf("%3d",value);
	}
	return 0;
}
