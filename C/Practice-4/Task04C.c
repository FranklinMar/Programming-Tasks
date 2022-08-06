/*
--------------
Name: Task04A.c
--------------
Description: Write a program, that solves the equation
by formula and prints result to the console.
--------------
*/

#include <stdio.h>
#include <math.h>

int main(){
  printf("The solution of :\n");
  printf(" 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...\n");
  float c = atan(1);
  printf("Solution: arctan 1 = PI/4 = %.4f.",c);
  return 0;
}
