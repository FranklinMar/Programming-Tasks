#include <stdio.h>
int main(void){
	int t = 2;
	t +=5;
	printf("The value of t:%d\n",t);
	t *= 10;
	printf("The value of t:%d\n",t);
	t -= 6;
	printf("The value of t:%d\n",t);
	t /= 8;
	printf("The value of t:%d\n",t);
	t %= 3;
	printf("The value of t:%d\n",t);
	return 0;
}