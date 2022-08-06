#include <stdio.h>

int main(void){
	double a;
	double b;
	printf("Enter symbols 'a' and 'b' to compare them(q to quit)\n");
	printf("a:");
	while((scanf("%lf",&a)) != 0){
	printf("b:");
	scanf("%lf",&b);
	a>b ? printf("a is bigger than b (a>b)\n"):a<b ? printf("b is bigger than a (a<b)\n"):printf("a is equal b (a=b)\n");
	getchar();
	printf("Enter symbols 'a' and 'b' to compare them(q to quit)\n");
	printf("a:");
	}
	return 0;
}