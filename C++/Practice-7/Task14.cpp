/*
------------------
Name: Task14.cpp
------------------------------------------------------------
Description: Overload the (bitwise) shift operators ≫ and ≪ 
  with respect to the coord class, to allow the following 
  operations (expressions):
  obj << integer
  obj >> integer
  
  Make sure your operators actually shift the values of "x" 
  and "y" by specified number of digits. 
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class coord {
	int x, y;
public:
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	friend void operator <<(coord &obj, int i);
	friend void operator >>(coord &obj, int i);
};

void operator <<(coord &obj, int i) {
	obj.x = obj.x << i;
	obj.y = obj.y << i;
}
void operator >>(coord &obj, int i) {
	obj.x = obj.x >> i;
	obj.y = obj.y >> i;
}

int main() {
	coord obj1(6, 6);
	int x, y;
	int A = 7;
	obj1 << A;
	obj1.get_xy(x, y);
	cout << "(obj1 << A) x: " << x << ", y: " << y << "\n";
	obj1 >> A;
	obj1.get_xy(x, y);
	cout << "(obj1 >> A) x: " << x << ", y: " << y << "\n";
	return 0;
}
