/*
------------------
Name: Task16.cpp
------------------------------------------------------------
Description: Show how to write and how to display format flags 
  for class "cout". Use member functions or manipulators.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

void showflags() {
	ios::fmtflags f = cout.flags();
	if (f & ios::boolalpha)
		cout << " boolalpha on\n";
	else
		cout << "boolalpha off\n";
	if (f & ios::dec)
		cout << " dec on\n";
	else
		cout << "dec off\n";
	if (f & ios::oct)
		cout << " oct on\n";
	else
		cout << "oct off\n";
	if (f & ios::hex)
		cout << " hex on\n";
	else
		cout << "hex off\n";
}

int main() {
	showflags();
	cout << (bool) 1 << endl;
	cout << 100 << endl;
	cout.unsetf(ios::dec);
	cout.setf(ios::boolalpha | ios::oct);
	showflags();
	cout << endl << (bool) 1 << endl;
	cout << 100 << endl << endl;
	cout << noboolalpha << hex << 100 << "\n";
	showflags();
	return 0;
}
