/*
----------------
Name: Task01.c
------------------------------------------------------------
Description: Write a program, that asks user for temperature 
  in Celsius, then converts it into Fahrenheit scale, and 
  then prints it out into the console.
------------------------------------------------------------
*/
#include <stdio.h>
int main(void) {
	float cel, far;
	printf("Enter temperature in C :");
	scanf("%f", &cel);
	far = cel * 9 / 5 + 32; // Formula of converting Celsius temperature into Fahrenheit
	printf("\n The same temperature in Fahrenheit is: %.2f \n",far);
	return 0;
}
