/*
--------------
Name: Task03.c
--------------
Description: Write a program, that uses 
nested 'for' loops, and demonstrate it.
--------------
*/
#include <stdio.h>
int main(void){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			printf("$");
		}
		printf("\n");
	}
	return 0;
}
