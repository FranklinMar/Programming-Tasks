/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Write a program to output the number 100 in the 
  decimal, hexadecimal, and octal number system. (Use the 
  formatting flags of the ios class).
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main() {
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << 100 << endl;
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << 100 << endl;
	cout.unsetf(ios::oct);
	cout.setf(ios::dec);
	cout << 100 << endl;
	return 0;
}
