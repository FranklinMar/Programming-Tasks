/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Perform Task 05 and 06 again, but now, instead 
  of the member functions and format flags, use I/O manipulators.
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

void center(char *s) {
	int len = strlen(s);
	len = len / 2;
	cout << setw(40 + len) << s << endl;
}
int main(){
	center("Hello there!");
	cout << "\n\t x    log(x)  log10(x)\n\n";
	for (int i = 2; i <= 100; i++) {
		cout << setw(10) << i << setw(10) << setprecision(5) << log(i) << setw(10) << setprecision(5) << log10(i) << endl;
	}
	return 0;
}
