/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: Write a program, that will sort 2-dimensional 
  array:
  
1) by Hoor sort method;
2) by Change sort method;
3) by Choose (Choice) sort method.
------------------------------------------------------------
*/
#include <stdio.h>
#define E 10

// Hoor sort method
void hoor();
// Change sort method
void change();
// Choose sort method
void choose();


int main(void) {
	int array[4][E] = {{6, 3, 34, 21, 13, -5, 0, 11, 43, 27},
			{17, 14, 32, 1, -8, 39, -27, 12, 11, 0},
			{15, 6, -9, 16, 38, 32, 60, -4, 2, 8},
			{-1, 44, 41, 19, -3, 5, 25, 16, 1, 7}};
	
	hoor(array[0], 0, E - 1);
	change(array[1]);
	choose(array[2]);
	choose(array[3]);
	for (int i = 0; i < 4; i++) {
		printf("Line[%d] ", i);
		for (int j = 0; j < E; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void hoor(int *array, int begin, int end) {
	int i = begin;
	int j = end;
	int s = -1;
	int condit = 1;
	int temp;
	if(begin >= end)
		return;
	do {
		if (condit == (*(array + i) > *(array + j))) {
			temp = *(array + i);
			*(array + i) = *(array + j);
			*(array + j) = temp;
			temp = i;
			i = j;
			j = temp;
			s *= -1;
			condit = !condit;
		}
		j += s;
	} while(j != i);
	hoor(array, begin, i-1);
	hoor(array, i+1,end);
}
void change(int *array) {
	int temp;
	for (int i = 0; i < E; i++) {
		for (int j = E - 1; j >= 1; j--)
			if(*(array + j - 1) > *(array + j)) {
				temp = *(array + j);
				*(array + j) = *(array + j - 1);
				*(array + j - 1) = temp;
			}
	}
}
void choose(int *array) {
	int temp;
	for(int i = 0; i < E; i++){
		for(int k = i, j = 0; j < E; j++){
			if(*(array + j) > *(array + k)){
				k = j;
			}
			temp = *(array + i);
			*(array + i) = *(array + k);
			*(array + k) = temp;
		}
	}
}
