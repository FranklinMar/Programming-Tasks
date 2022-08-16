/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: Design a natural and decimal table printing 
  program logarithms of numbers from 2 to 100. The format of 
  the table is as follows: right alignment, field width - 10 
  characters, accuracy (precision) - 5 decimal places.
------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.width(10);
	cout.precision(5);
	cout << "\t x    log(x)  log10(x)\n\n";
	for (int i = 2; i <= 100; i++) {
		cout.width(10);
		cout << i;
		cout.width(10);
		cout.precision(5);
		cout << log(i);
		cout.width(10);
		cout.precision(5);
		cout << log10(i)<<endl;
	}
	return 0;
}
