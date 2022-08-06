/*
--------------
Name: Task04A.c
--------------
Description: Write a program, that gets value
for 'x' variable, then solves the equation by formula
and prints result to the console.
--------------
*/
#include <stdio.h>
#include <math.h>

int main(){
  float x;
  printf("Enter X to solve the equation:\n");
  printf("1 / (1 + x*x) = 1 - x^2 + x^4 - x^6 + x^8 - ...\n");
  scanf("%f", &x);
  float c = 1 / (1 + x*x);
  printf("Result:%.4f.", c);
  return 0;
}
