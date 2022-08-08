/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Write a program that uses I/O from C++, for 
  passing as input 2 integers from the keyboard and then 
  printing on the screen the result of raising the 1-st 
  number to the power of 2-nd. (Example: input 2 and 4;
  result: 16.
------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int x, y;
	cout << "Enter 2 integers 'a' and 'b' to raise a to the power of b.\n";
	cout << "Operation:a^b\n";
	cout << "a:";
	cin >> x;
	cout << "b:";
	cin >> y;
	cout << x << "^" << y << " == " << pow(x, y) << "\n";
	return 0;
}
