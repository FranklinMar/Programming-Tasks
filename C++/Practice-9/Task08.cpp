/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Write instructions for the output of the number 
  100 in the hexadecimal number system, showing the base of 
  the number system (0x). To complete the task use the 
  setiosflags() manipulator.
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << setiosflags(ios::showbase) << hex << 100 << endl;
	return 0;
}
