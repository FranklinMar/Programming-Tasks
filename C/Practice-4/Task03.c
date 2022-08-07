/*
----------------
Name: Task03.c
------------------------------------------------------------
Description: Write a program, that gets the number of 
  elements to the expression and calculates the solution by 
  using iterative formula, and print result to the console.
------------------------------------------------------------
*/
#include <stdio.h>
#include <math.h>
int main(void){
	int N, n;
	float sum = 1;
	float a;
	printf("Enter a number of elements 'N' of expression:\n");
	printf("1 - 1/3 + 1/5 - 1/7 + 1/9 ...\n");
	printf("N:");
	scanf("%d", &N);
	for(n = 1; n < N; n++) {
		a = pow((-1), N + 1) / (2 * N - 1);
		sum = sum + a;
	}
	printf("Formula: a(N) = ((-1) ^ N + 1) / 2N - 1\n");
	printf("Result of the expression with %d elements: %f", N, sum);
	return 0;
}
