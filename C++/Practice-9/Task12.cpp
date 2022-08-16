/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Create a class for storing the integer and its 
  smallest divisor. Create for this class custom input and 
  output functions.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class integer {
	int dec;
	int divid_least;
public:	
	integer () { divid_least = 1;}
	integer(int n){ dec = n; divid_least = 1; }
	friend ostream &operator <<(ostream &stream, integer &obj);
	friend istream &operator >>(istream &stream, integer &obj);
};

ostream &operator <<(ostream &stream, integer &obj) {
	stream << "Integer: " << obj.dec << " \nThe least divider : " << obj.divid_least << endl;
	return stream;
}
istream &operator >>(istream &stream, integer &obj) {
	stream >> obj.dec;
	return stream;
}

int main() {
	integer ark;
	cin >> ark;
	cout << ark;
	return 0;
}
