#include <stdio.h>
int main(void) {
	float cel, far;
	printf("Enter temperature in C :");
	scanf("%f", &cel);
	far = cel * 9 / 5 + 32; // Формула для переведення температури в Фаренгейти
	printf("\n The same temperature in Fahrenheit is: %.2f \n",far);
	return 0;
}