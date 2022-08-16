/*
------------------
Name: Task15.cpp
------------------------------------------------------------
Description: Rewrite your answers to Tasks 13 and 14 so that 
  I/O handlers (manipulators) are used.
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << hex << 100 << endl;
	cout << oct << 100 << endl;
	cout << dec << 100 << endl;
	cout << setw(20) << setprecision(6) << left << setfill('*') << 1000.5364 << endl;
	return 0;
}
