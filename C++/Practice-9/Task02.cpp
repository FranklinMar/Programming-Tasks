/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: Write a program, which would set the flags for 
  the "cout" stream in such a way, so that integers, if they 
  are positive, are displayed with a "+" sign. Show that your 
  set format flags is correct.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::showpos);
	cout << 25 << " " << 1 << endl;
	cout.unsetf(ios::showpos);
	cout << 25 << " " << 1 ;
	return 0;
}
