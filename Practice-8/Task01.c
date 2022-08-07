/*
--------------
Name: Task01.c
--------------
Description: Write a program, that will calculate the Area 
and Circumference of circle by radius read from user 
input with using pointers and adress to variables.
--------------
*/
#include <stdio.h>
#include <math.h>

void square(double radius, double *square, double *circumference);

int main(void) {
	double r, s, c;
	int i;
	do {
		printf("Please enter the Radius of circle:");
		scanf("%lf", &r);
		if (r <= 0) {
			printf("Radius can't be negative or 0.\nPlease use positive rational numbers only. \n");
			i = 1;
		} else
			i = 0;
	} while(i);
	square(r, &s, &c);
	printf("Radius of circle:%.2lf\nSquare of circle:%.2lf\nCircumference of circle:%.2lf", r, s, c);
	return 0;
}
void square(double radius, double *square, double *circumference) {
	*square = M_PI * radius * radius;
	*circumference = 2 * M_PI * radius;
}
