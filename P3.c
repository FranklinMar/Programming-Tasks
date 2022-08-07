#include <stdio.h>
#define N 3
void show1(const double arr1[],int n);
void show2(const double arr2[][3],int n);
int main(void){
	show1((double[]){8,3,9},3);
	show2((double[][3]){{8,3,9},{5,4,1}},2);
	return 0;
}
void show1(const double arr1[],int n){
	printf("Function show 1:");
	for(int i=0;i < n;i++){
		printf("%f ",arr1[i]);
	}
	printf("\n");
}
void show2(const double arr2[][3],int n){
	printf("Function show 2:\n");
	for(int i=0;i < n;i++){
		printf("Row %d:",i+1);
		for(int j=0;j < 3;j++){
			printf("%f ",arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}