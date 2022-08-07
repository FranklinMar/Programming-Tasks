#include <stdio.h>
void increase(double *a,double *b);
void decrease(double *a,double *b);
int main(void){
	// 1 Частина
	double a,b;
	printf("Please enter 2 numbers to swap them in order of increasing:");
	scanf("%lf %lf",&a,&b);
	increase(&a,&b);
	printf("Order of increasing:\n1:%lf\n2:%lf\n",a,b);
	// 2 Частина
	printf("Please enter 2 numbers to swap them in order of decreasing:");
	scanf("%lf %lf",&a,&b);
	decrease(&a,&b);
	printf("Order of decreasing:\n1:%lf\n2:%lf\n",a,b);
	return 0;
}
void increase(double *a,double *b){
	double temp;
	if(*a>*b){
		temp=*a;
		*a=*b;
		*b=temp;
	}
}
void decrease(double *a,double *b){
	double temp;
	if(*a<*b){
		temp=*a;
		*a=*b;
		*b=temp;
	}
}