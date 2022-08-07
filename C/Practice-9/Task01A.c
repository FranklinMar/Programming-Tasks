/*
--------------
Name: Task01A.c
--------------
Description: Write a program, that will complete
next tasks with pointers: 
- Get 2 matrixes with elements and dimensions 
(1 <= x <= 10 interval) that are determined by user.
- Find the sum of 2 matrixes (with all neccessary checkings).
--------------
*/
#include <stdio.h>

// Get matrix dimensions from user
void getsize(int *h, int *w);

int main(void){
	int height, width;
	getsize(&height, &width);
	float m1[height][width];
	float m2[height][width];
	printf("Enter %d elements of the matrix №1 line by line(use space):", height * width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%f", &m1[i][j]);
		}
	}
	printf("Enter %d elements of the matrix №2 line by line(use space):", height * width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%f", &m2[i][j]);
		}
	}
	printf("\nMatrix №1:\n");
	for (int i = 0; i < height; i++) {
		printf("|");
		for (int j = 0; j < width; j++) {
			printf("%6.3f ", *(*(m1 + i) + j));
		}
		printf("|\n");
	}
	printf("\nMatrix №2:\n");
	for (int i = 0; i < height; i++) {
		printf("|");
		for (int j = 0; j < width; j++) {
			printf("%6.3f ", *(*(m2 + i) + j));
		}
		printf("|\n");
	}
	printf("\nSum of Matrix:\n");
	for (int i = 0; i < height; i++) {
		printf("|");
		for(int j = 0; j < width; j++){
			printf("%6.3f ", *(*(m1 + i) + j) + *(*(m2 + i) + j));
		}
		printf("|\n");
	}
	return 0;
}
void getsize(int *h,int *w){
	printf("Please enter the size of the matrix.(use space):\n");
	printf("Height(lines):");
	scanf("%d",h);
	printf("\nWidth(columns):");
	scanf("%d",w);
	if (*h <= 0 || *w <= 0){
		printf("*Error*Negative sized matrix doesn't exist.\n.The Height and Width will be taken as 1.\n");
		*h = 1;
		*w = 1;
	} else if (*h > 10 || *w > 10) {
		printf("*Error*Size of matrix can't be bigger than 11.\nThe Height and Width will be taken as 10\n");
		*h = 10;
		*w = 10;
	}
	printf("\n");
}
