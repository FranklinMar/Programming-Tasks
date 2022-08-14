/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: Write a program that uses the "new" operator to
  allocate dynamic memory to float, long and char variables. 
  Give values to those dynamic variables and print those 
  values to the screen. At the end, free all dynamically 
  allocated variables (with dynamic memory) with "delete" 
  operator.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main(){
	float *floatp;
	long *longp;
	char *charp;
	floatp = new float;
	longp = new long;
	charp = new char;
	if (!floatp || !longp || !charp) {
		cout << "Allocation error \n";
		return 0;
	}
	*floatp = 6.5;
	*longp = 600000;
	*charp = 'A';
	cout << "\nFloat:" << *floatp << "\nLong:" << *longp << "\nChar:" << *charp;
	delete floatp;
	delete longp;
	delete charp;
	return 0;
}
