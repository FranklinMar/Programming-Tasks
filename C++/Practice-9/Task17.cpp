/*
------------------
Name: Task17.cpp
------------------------------------------------------------
Description: Create custom input and output functions for the 
  next class:
  
class pwr {
 int base;
 int exponent;
 double result; // base to the exponent power
public:
 pwr(int b, int e);
};
pwr::pwr(int b, int e) {
 base = b;
 exponent = e;
 result = 1;
 for ( ; e; e--)
 result = result * base;
}
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class pwr {
  int base;
  int exponent;
  double result; // base to the exponent power
public:
  pwr() { base = 0; exponent = 0; result = 0; }
  pwr(int b, int e);
  friend ostream &operator <<(ostream &stream, pwr &obj);
  friend istream &operator >>(istream &stream, pwr &obj);
};
pwr::pwr(int b, int e) {
  base = b;
  exponent = e;
  result = 1;
  for (; e; e--)
    result = result * base;
}
ostream &operator <<(ostream &stream, pwr &obj) {
	stream << "Base: " << obj.base << " | Exponent: " << obj.exponent << " | Result: " << obj.result << endl;
	return stream;
}
istream &operator >>(istream &stream, pwr &obj) {
	stream >> obj.base >> obj.exponent;
	obj.result = 1;
	for (int e = obj.exponent; e; e--)
		obj.result = obj.base * obj.result;
	return stream;
}

int main() {
	pwr num;
	cout << "Enter base < space > exponent : \n";
	cin >> num;
	cout << num;
	return 0;
}
