/*
----------------
Name: Task05.c
------------------------------------------------------------
Description: Write a program, that prints out fractions 
  of (1/n), where n is odd, via loop.
------------------------------------------------------------
*/
#include <stdio.h>
int main(void){
	int i = 1;
	float n = 1.0;
	printf("Watch out! Here come a bunch of fractions!\n");
	while (i<30){
		n=1/(float)i;
		printf(" %.3f\n",n);
		i=i+2;
	}
	printf("That's all folks!\n");
	return 0;
}
