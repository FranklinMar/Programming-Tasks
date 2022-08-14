/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Using the "new" operator, show how to dynamically 
  allocate variable "double" type and pass it the initial 
  value -123.0987.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main() {
	double *value;
	value = new double;
	*value = -123.0987;
	cout << *value << endl;
	delete value;
	return 0;
}
