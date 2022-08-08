/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: In Unit 2 you were overloading abs() function, 
  so it could return absolute values of int, long and double 
  types. Modify the program, so these functions were treated 
  as inline.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

inline int cabs(int n) {
	return ((n < 0) ? -n : n);
}
inline long cabs(long n) {
	return ((n < 0) ? -n : n);
}
inline double cabs(double n) {
	return ((n < 0) ? -n : n);
}

int main() {
	cout << "Absolute value of -30: " << cabs(-30) << "\n";
	cout << "Absolute value of -30L: " << cabs(-30L) << "\n";
	cout << "Absolute value of -30.35: " << cabs(-30.35) << "\n";
	return 0;
}
