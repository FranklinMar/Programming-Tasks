/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Write a neg() function that changes the sign of 
  its integer parameter to the opposite. Write a function in 
  two ways: the first is using a pointer parameter and the 
  second must have a reference parameter. Make a short 
  program for demonstration of both features.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void neg(double	 *number) {
	*number = -*number ;
}

void neg(double &number) {
	number = -number ;
}

int main() {
	double digit = 23;
	cout << "Current digit: " << digit << endl;
	neg(&digit);
	cout << "Digit after neg function with pointer: " << digit << endl;
	neg(digit);
	cout << "Digit after neg function with reference: " << digit << endl;
	return 0;
}
