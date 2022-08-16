/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: Write a program, that would set flags for the 
  cout thread, so that decimal points are always shown when 
  fractional values are displayed. Other than this, the 
  floating point values should be displayed in a scientific 
  notation with the symbol "E" in the upper case.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main(){
	cout.setf(ios::showpoint);
	cout << (float) 25 << endl;
	cout.setf(ios::scientific | ios::uppercase);
	cout << 20.1;
	return 0;
}
