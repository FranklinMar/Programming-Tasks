/*
------------------
Name: Task14.cpp
------------------------------------------------------------
Description: Write a program to output a value of 1000.5364 
  in a 20-character field, with an alignment to the left, 
  with two positions after the decimal point and a symbol * 
  as the fill symbol. (Use the formatting flags of the "ios" 
  class).
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main(){
	cout.setf(ios::left);
	cout.width(20);
	cout.precision(6);
	cout.fill('*');
	cout << 1000.5364 << endl;
	return 0;
}
