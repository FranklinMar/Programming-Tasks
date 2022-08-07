/*
----------------
Name: Task02.c
------------------------------------------------------------
Description: Write a program, that will swap the values of 
  variables in ascending and descending order by using 
  pointers and address.
------------------------------------------------------------
*/
#include <stdio.h>

void increase(double *a,double *b);
void decrease(double *a,double *b);

int main(void){
	// Part 1
	double a, b;
	printf("Please enter 2 numbers to swap them in order of increasing:");
	scanf("%lf %lf", &a, &b);
	increase(&a, &b);
	printf("Order of increasing:\n1:%lf\n2:%lf\n", a, b);
	// Part 2
	printf("Please enter 2 numbers to swap them in order of decreasing:");
	scanf("%lf %lf", &a, &b);
	decrease(&a, &b);
	printf("Order of decreasing:\n1:%lf\n2:%lf\n", a, b);
	return 0;
}
void increase(double *a, double *b){
	double temp;
	if (*a > *b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
void decrease(double *a, double *b){
	double temp;
	if(*a < *b){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
