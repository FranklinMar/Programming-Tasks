/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: Write a program to display the 10/3 division 
  result with four digits after the decimal point. To do this, 
  use the member functions of the ios class. Write a second 
  version of this program using the I/O manipulators.
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout.precision(5);
	cout << 10./3 << "\n\n";
	
	cout << setprecision(5) << 10./3 << '\n';
	return 0;
}
