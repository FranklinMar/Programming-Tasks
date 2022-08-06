/*
--------------
Name: Task02.c
--------------
Description: Write a program, that gets values from user for 
quadratic equation and uses arrays to store them, then 
solves it and prints the solution to the console.
--------------
*/
#include <stdio.h>
#include <math.h>
#define S 3
int main(void){
	float a[S];
	int i = 0;
	printf("Press any number to start the program('q' to quit):\n");
	while(scanf("%f", &a[i]) == 1){
	printf("Please enter values of variables 'a,b,c' to solve the 'ax*x+bx+c=0' equation:\n");
	for(i = 0; i < S; i++){
		scanf("%f",&a[i]);
	}
	for(i = 0; i < S; i++){
		printf(" %f ",a[i]);
	}
	printf("\n");
	float d = pow(a[1], 2) + (-4) * a[0] * a[2];
	if(d > 0){
		float x1 = (-1 * a[1] + sqrt(d)) / 2 * a[0];
		printf("x1 = %f\n", x1);
		float x2 = (-1 * a[1] - sqrt(d)) / 2 * a[0];
		printf("x2 = %f\n", x2);
	} else if(d == 0) {
		float x = -1 * a[1] / 2 * a[0];
		printf("x = %f\n", x);
	} else {
		printf ("ERROR.There is no solution.There is no square root out of d<0\n");	
	}
	printf("Press any number to start the program('q' to quit):\n");
	}
	return 0;
}
