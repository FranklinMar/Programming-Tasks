/*
----------------
Name: Task04.c
------------------------------------------------------------
Description: Write a program, that will have next functions:

1) returns a max value from array of integers;
2) returns an index of max value from double type array;
3) returns the result of difference between the biggest 
   and the lowest elements of double type array.

- Arrays can be 1-dimensional.
- The values must be taken from user console input.
- Do not forget about the checking of correctness of user 
   input (to avoid errors with invalid values of the 
   elements and the possibility of going out of the array's 
   bounds).
------------------------------------------------------------
*/
#include <stdio.h>

// Returns max value of array
int max(int array[], int n);
// Returns index of max value of array
int maxindex(double array[], int n);
// Returns difference between the biggest 
// and the lowest elements of array
double minus(double array[], int n);

int main(void){
	int n;
	int l = 1;
	printf("Enter number of elements of array:\n");
	while (l) {
		printf("N:");
		scanf("%d", &n);
		if (n <= 0) {
			printf("Number of elements of array can't be negative/0\n");
			getchar();
		} else {
			l = 0;
		}
	}
	int in[n];
	double doub[n];
	printf("Enter %d elements of array #1:", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	getchar();
	printf("Enter %d elements of array #2:",n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &doub[i]);
	}
	int maxi = max(in,n);
	int ind = maxindex(doub,n);
	double min = minus(doub,n);
	printf("Maximum element of array #1:%d\n",maxi);
	printf("Index of Maximum element of array #2:%d\n",ind);
	printf("Difference of Maximum and Minimum element of array #2:%lf\n",min);
	return 0;
}
int max(int array[], int n) {
	int max = array[0];
	for (int i = 0; i < n; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	return max;
}
int maxindex(double array[], int n) {
	int index = 0;
	double max = array[0];
	for (int i = 0; i < n; i++) {
		if (max < array[i]) {
			max = array[i];
			index = i;
		}
	}
	return index;
}
double minus(double array[], int n) {
	double min = array[0];
	double max = array[0];
	double result;
	for (int i = 0; i < n; i++) {
		if (max < array[i]) {
			max = array[i];
		}
		if(min > array[i]) {
			min = array[i];
		}
	}
	result = max - min;
	return result;
}
