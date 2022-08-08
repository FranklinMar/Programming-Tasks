/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Create your own function min(), that returns 
  the lowest from 2 number arguments. Overload min() 
  function, so it would take as arguments types of char, 
  int and double (look Unit 2 "Introducing Function Over-
  -loading").
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

char min(char a, char b) {
	if ((int) a < (int) b) {
		return a;
	} else {
		return b;
	}
}

int min(int a, int b) {
	int m = (a < b) ? a : b;
	return m;
}

double min(double a, double b) {
	double m = (a < b) ? a : b;
	return m;
}

int main(){
	cout << "Min of 'A' and 'b' is :" << min('A','b') << '\n';
	cout << "Min of 10 and -10 is :" << min(10,-10) << '\n';
	cout << "Min of 15,6 and 6.5 is :" << min(15.6,6.5) << '\n';
	return 0;
}
