/*
--------------
Name: Task02A.c
--------------
Description: ---
(Modified Task02)
--------------
*/
#include <stdio.h>
#include <ctype.h>

void order(double *a, double *b, int i);

int main(void){
	double a, b;
	int d, i;
	do {
	printf("Please choose the mode to place 2 number in order:\n1.Increasing.\n2.Decreasing\n");
	scanf("%d", &i);
	if (i < 1 || i > 2) {
		printf("Error.You have entered wrond type of data.\nUse 1 or 2.Please try again.");
		d = 1;
	} else 
		d = 0;
	} while(d);
	printf("Please enter 2 numbers to swap them in order of increasing:");
	scanf("%lf %lf", &a, &b);
	order(&a, &b, i);
	printf("Order:\nA:%lf\nB:%lf", a, b);
	return 0;
}
void order(double *a, double *b, int i){
	double temp;
	if (i == 1) {
		if (*a > *b) {
			temp = *a;
			*a = *b;
			*b = temp;
		}
	}
	if (i == 2) {
		if (*a < *b) {
			temp = *a;
			*a = *b;
			*b = temp;
		}
	}
}
