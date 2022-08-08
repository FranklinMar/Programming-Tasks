/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: Rewrite the program below, which is written on 
  C language, into the C++ style of I/O.
  
  Program:

#include <stdio.h>
int main(void) {
  int a, b, d, min;
  printf("Enter two numbers: ");
  scanf("%d%d", &a, &b);
  min = a>b?b:a;
  for (d=2; d<min; d++)
		if (((a%d) == 0) && ((b%d) == 0))
			break;
	if (d==min) {
		printf("No common denominators\n");
		return 0;
	}
	printf ("The lowest common denominator is %d\n", d);
	return 0;
}
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main() {
	int a, b, d, min;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	min = (a > b) ? b : a;
	for (d = 2; d < min; d++) {
		if ((a % d == 0) && (b % d == 0))
			break;
	}
	if (d == min) {
		cout << "No common denominators\n";
		return 0;
	}
	cout << "The lowest common denominator is " << d << '\n';
	return 0;
}
