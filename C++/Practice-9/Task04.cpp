/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Write a program that preserves the current state 
  of flags format, sets the "showbase" and "hex" flags, displays 
  the 100, and then returns flags in their original state.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main() {
	ios::fmtflags flag;
	flag = cout.flags();
	cout << "Number:" << 100 << "\n";
	cout.unsetf(ios::dec);
	cout.setf(ios::hex | ios::showbase);
	cout << 100 << "\n";
	cout.flags(flag);
	return 0;
}
