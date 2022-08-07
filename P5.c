#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void rev(int *array,int n);
int main(void){
	int n;
	int l = 1;
	printf("Enter number of elements of array:\n");
	while(l){
		printf("N:");
		scanf("%d",&n);
		if(n<=0){
			printf("Number of elements of array can't be negative/0\n");
			getchar();
		}else{
			l=0;
		}
	}
	int array[n];
	int c;
	printf("Choose the type of filling the array:\n1.Manually\n2.Fill up with random numbers\n");
	l = 1;
	while(l){
		printf("Mode:");
		scanf("%d",&c);
		if(c==1 || c==2){
			l=0;
		}else{
			printf("Choose only 1 or 2:\n");
			getchar();
		}
	}
	if(c==1){
		printf("Enter %d elements of array:",n);
		for(int i=0;i<n;i++){
			scanf("%d",&array[i]);
		}
	}else{
		for(int i=0;i<n;i++){//j = i+rand()/(RAND_MAX / (MAX-i)+1)
			*(array+i) = rand()%198-99;
		}
	}
	printf("Array:");
	for(int i=0;i<n;i++){
			printf("%d ",*(array+i));
	}
	rev(&array[0],n);
	printf("\nArray:");
	for(int i=0;i<n;i++){
			printf("%d ",*(array+i));
	}
	return 0;
}
void rev(int *array,int n){
	int mass[n];
	for(int i = 0,j = n-1;i<n;i++,j--){
		*(mass+i) = *(array+j);
	}
	for(int i = 0;i<n;i++){
		*(array+i) = *(mass+i);
	}
}