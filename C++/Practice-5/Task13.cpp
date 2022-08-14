/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Try to find a useful use for the independent link.
  Write a demo program.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
	int variable = 23;
	const int &ref = variable;
	cout << "Constant values can't be changed in most cases: " << ref << endl;
	variable = 6;
	cout << "But this one can! Look : " << ref << endl;
	cout << "Variable : " << variable << endl;
	return 0;
}
