/*
----------------
Name: Task04B.c
------------------------------------------------------------
Description: Write a program, that gets value for 'x' 
  variable, then solves the equation by formula and prints 
  result to the console.
------------------------------------------------------------
*/
#include <stdio.h>
#include <math.h>

int main(){
  float x;
  printf("Enter X to solve the equation:\n");
  printf("arctan x = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + (x^9)/9 - ...\n");
  scanf("%f", &x);
  float c = atan(x);
  printf("Result:%.4f.", c);
  return 0;
}
