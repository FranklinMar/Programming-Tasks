/*
----------------
Name: Task04.c
------------------------------------------------------------
Description: Write a program, that calculates factorial 
  without using recursion.
------------------------------------------------------------
*/
#include <stdio.h>

unsigned long long factorial(int n);

int main(void){
  int h;
  printf("Please Enter an integer number to find factorial:");
  scanf("%d", &h);
  if (h >= 0) {
    printf("Factorial of :%llu", factorial(h));
  } else {
    printf("Error.Factorial of a negative number doesn't exist");
  }
  return 0;
}

unsigned long long factorial(int n) {
  unsigned long long f = 1;
  for (int i = 1; i <= n; i++) {
    f = f * i;
  }
  return f;
}
