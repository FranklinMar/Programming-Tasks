#include <stdio.h>
#include <math.h>
int factorial(int n){
	return n == 0 ? 1 : n * factorial(n - 1);
}
float mycos(float x){
	float sum = 0;
	for (int i=0;i<10;i++){
		sum = sum + pow(-1,i)*pow(x,2*i)/factorial(2*i);
	}
	return sum;
}

int main(void){
	float a[10];
	printf("Enter 'x' 10 times to find Cos(x):\n");
	int j=0;
	while(j!=10){
		scanf("%f",&a[j]);
		j++;
	}
	printf("\n");
	printf("|  x  |   mycos(x)    |   cos(x)      |\n");
	for(int i=0;i<10;i++){
		printf("| %.1f |   %.16f  |   %.16f  |\n", a[i], mycos(a[i]), cos(a[i]));
	}
	return 0;
}