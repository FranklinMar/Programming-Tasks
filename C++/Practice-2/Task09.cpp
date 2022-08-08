/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Standart library C++ contains 3 functions: 
  double atof(const char *s);
  int atoi(const char *s);
  long atol(const char *s);
  These functions return number value, that is contained 
  within a string, contained in "s" pointer. Pay attention, 
  that atof() returns double, atoi() returns int and atol() 
  returns long. Why you cannot overload these functions?
  Show it on code example.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
/* If moved out of comments - ambigious error occurs.
It occurs because to overload a function, they need to 
differ by parameter types or amount.

double ato(char *c){
	return atof(c);
}
int ato(char *c){
	return atoi(c);
}*/
long int ato(char *c){
	return atol(c);
}
int main(){
	char string[20] = "Here is the string.";
	char *strp = &string[0];
	cout << "Result of function ato:" << ato(strp);
	return 0;
}

