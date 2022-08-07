/*
----------------
Name: Task03.c
------------------------------------------------------------
Description: Write a program, that get a string with several 
  numbers (numbers must be integers, and total amount of 
  them shouldn't be less than 10), then implement sorting of 
  entered array by next methods in the next order: 
  
1) Bubble sort algorithm (bubble method);
2) Shuffling of the array (shuffle method);
3) Shell sort algorithm (shell method);
4) Shuffling of the array again (shuffle method);
5) Hoor sort algorithm (hoor method).
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MIN 10


// Testing input - "1 23 5 6 1 6 1 2 3 1 21 11 14 18 9 4 8 7 17 12"

// Display the array
void show(int *array);
// Bubble sort
void bubble();
// Random Shuffling
void shuffle();
// Shell sort
void shell();
// Hoor sort
void hoor();

int main(void){
	int array[MAX];
	printf("Enter 20 Integer numbers:");
	
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &array[i]);
	}
	printf("\nFormer array:");
	show(array);
	
	bubble(&array);
	printf("\n\nBubble sorted array:");
	show(array);
	
	shuffle(&array);
	printf("\n\nShuffled array:");
	show(array);
	
	shell(&array);
	printf("\n\nShell sorted array:");
	show(array);
	
	shuffle(&array);
	printf("\n\nShuffled array:");
	show(array);
	
	hoor(&array, 0, MAX-1);
	printf("\n\nHoor sorted array:");
	show(array);
	return 0;
}

void show(int *array) {
	for (int i = 0; i < MAX; i++) {
		printf(" %d", *(array + i));
	}
}
void bubble(int *array){
	int temp;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (*(array + i) > *(array + j)) {
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			}
		}
	}
}

void shuffle(int *array) {
	//srand(time(0));
	int j;
	int temp;
	for (int i = 0; i < MAX; i++) {
		//j = i + rand() % (MAX - i);
		j = i + rand() / (RAND_MAX / (MAX - i) + 1);
		temp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = temp;
	}
}
void shell(int *array) {
	int temp;
	for (int half = MAX / 2; half > 0; half = half / 2) {
		for (int i = half; i < MAX; i++) {
			for (int j = i - half; j >= 0 && 
			     (*(array + j) > *(array + j + half)); j = j - half){
				temp = *(array + j);
				*(array + j) = *(array + j + half);
				*(array + j + half) = temp;
			}
		}
	}
}
void hoor (int *array, int begin, int end) {
	int i = begin;
	int j = end;
	int s = -1;
	int condit = 1;
	int temp;
	if (begin >= end)
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
	hoor(array, i+1, end);
}
