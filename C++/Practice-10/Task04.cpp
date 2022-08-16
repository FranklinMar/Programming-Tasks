/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Create your own output manipulator to display 
  the current system time and date. Name it as tdm() manipulator.
------------------------------------------------------------
*/
#include <iostream>
#include <ctime>
using namespace std;

ostream &tdm(ostream &o) {
	time_t result = time(NULL);
	struct tm *info = localtime(&result);
	o << asctime(info);
	return o;
}

int main() {
	cout << tdm << endl;
	return 0;
}
