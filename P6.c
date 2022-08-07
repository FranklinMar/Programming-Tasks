#include <stdio.h>

int main(void) {
	int n;
	int l = 1;
	printf("Enter number of elements of array:\n");
	while (l) {
		printf("N:");
		scanf("%d", &n);
		if(n <= 0) {
			printf("Number of elements of array can't be negative/0\n");
			getchar();
		} else {
			l = 0;
		}
	}
	int arr1[n];
	int arr2[n];
	int arr3[n];
	printf("Enter %d elements of array #1:", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	getchar();
	printf("Enter %d elements of array #2:", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}
	printf("Array#1:");
	for (int i = 0; i < n; i++) {
			printf("%d ", *(arr1 + i));
	}
	printf("\nArray#2:");
	for (int i = 0; i < n; i++) {
			printf("%d ", *(arr2 + i));
	}
	for (int i = 0; i < n; i++) {
			*(arr3 + i) = *(arr1 + i) + *(arr2 + i);
	}
	printf("\nArray#3:");
	for (int i = 0; i < n; i++) {
			printf("%d ", *(arr3 + i));
	}
	return 0;
}
