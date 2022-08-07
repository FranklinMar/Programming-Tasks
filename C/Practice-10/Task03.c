/*
--------------
Name: Task03.c
--------------
Description: Write a program, that will have
next functions:

 void show1(const double arr1[], int n);
 void show2(const double arr2[][3], int n);
 
where inside show1() n – number of elements of array,
and inside show2() n – number of rows of array.

Also, implement next goals:
a) when calling function show1(), it must have compound literals, 
that consists of values 8, 3, 9; and then 3.
b) when calling function show2(), it must have compound literals,
that consists of values 8, 3, 9 - values for the first row, and of
values 5, 4, 1 - values for the second row (and then 2).
--------------
*/
#include <stdio.h>
#define N 3

void show1(const double arr1[], int n);
void show2(const double arr2[][3], int n);

int main(void) {
	show1((double[]) {8, 3, 9}, 3);
	show2((double[][3]) {{8, 3, 9}, {5, 4, 1}}, 2);
	return 0;
}

void show1(const double arr1[], int n) {
	printf("Function show 1:");
	for (int i = 0; i < n; i++) {
		printf("%f ", arr1[i]);
	}
	printf("\n");
}
void show2(const double arr2[][3], int n) {
	printf("Function show 2:\n");
	for (int i = 0; i < n; i++) {
		printf("Row %d:", i + 1);
		for (int j = 0; j < 3; j++) {
			printf("%f ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
