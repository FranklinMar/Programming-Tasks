#include <stdio.h>

int max(int array[],int n);
int maxindex(double array[],int n);
double minus(double array[],int n);

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
	int in[n];
	double doub[n];
	printf("Enter %d elements of array #1:",n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	getchar();
	printf("Enter %d elements of array #2:",n);
	for(int i=0;i<n;i++){
		scanf("%lf",&doub[i]);
	}
	int maxi = max(in,n);
	int ind = maxindex(doub,n);
	double min = minus(doub,n);
	printf("Maximum element of array #1:%d\n",maxi);
	printf("Index of Maximum element of array #2:%d\n",ind);
	printf("Difference of Maximum and Minimum element of array #2:%lf\n",min);
	return 0;
}
int max(int array[],int n){
	int max = array[0];
	for(int i=0;i<n;i++){
		if(max<array[i]){
			max = array[i];
		}
	}
	return max;
}
int maxindex(double array[],int n){
	int index = 0;
	double max = array[0];
	for(int i=0;i<n;i++){
		if(max<array[i]){
			max = array[i];
			index = i;
		}
	}
	return index;
}
double minus(double array[],int n){
	double min = array[0];
	double max = array[0];
	double result;
	for(int i=0;i<n;i++){
		if(max<array[i]){
			max = array[i];
		}
		if(min>array[i]){
			min = array[i];
		}
	}
	result = max - min;
	return result;
}