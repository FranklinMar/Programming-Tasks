/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Create a function myroot(), which returns 
  the square root of its argument. Overload myroot() in 
  three ways (see Unit 2 "Introducing Function Overloading"):
  to get square root of integer, long integer and double 
  number. (For calculating square root you can use sqrt() 
  from standart library.
------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

int myroot(int a) {
	return sqrt(a);
}
long int myroot(long int a) {
	return sqrt(a);
}
double myroot(double a) {
	return sqrt(a);
}

int main() {
	cout << "Square root of 100:" << myroot(100) << "\n";
	cout << "Square root of 100L:" << myroot(100L/* 100000000*/) << "\n";
	cout << "Square root of 56,25:" << myroot(56.25) << "\n";
	return 0;
}
