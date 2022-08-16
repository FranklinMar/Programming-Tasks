/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: Create your sethex() output manipulator, which 
  performs the output in the hexadecimal number system and 
  sets the flags "uppercase" and "showbase". In addition, 
  create a reset() manipulator that reverts changes made by 
  the sethex() manipulator.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

ostream &sethex(ostream &o) {
	o << hex << uppercase << showbase;
	return o;
}
ostream &reset(ostream &o) {
	o.unsetf(ios::hex | ios::uppercase | ios::showbase);
	//o.setf(ios::dec);
	return o;
}

int main() {
	cout << sethex << 100 << '\n';
	cout << sethex << reset << 100 << '\n';
	return 0;
}
