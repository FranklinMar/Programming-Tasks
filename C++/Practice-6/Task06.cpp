/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Most C++ compilers use non-standard functions,
  controlling cursor positioning and other similar actions.
  Do you remember that you were previously allowed to use 
  any compilers, not just g++? If the compiler, which you are 
  using, such functions can be applied, create a myclreol() 
  function that erases the line, starting from the current 
  cursor position to the end of the line. Pass this function 
  parameter that specifies the number of positions to be 
  erased. If the parameter is not set, then By default, the 
  entire line should be erased. Otherwise, it must be erased 
  the number of character positions specified by the parameter.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

void myclreol(int x = 80) {
	for (int i = 0; i < x; i++) {
		cout << '\b';
	}
	for (int i = 0; i < x; i++) {
		cout << ' ';
	}
}
int main() {
	cout << "Hello there!!!";
	myclreol(5);	
	//myclreol();
	return 0;
}
