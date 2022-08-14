/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: Overload the minus '-' operator with reference 
  to the coord class. Create its prefix and postfix forms.
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
	friend coord operator -(const coord &obj, int i);
	friend coord operator -(int i, const coord &obj);
};
coord operator -(const coord &obj, int i) {
	coord temp;
	temp.x = obj.x - i;
	temp.y = obj.y - i;
	return temp;
}
coord operator -(int i, const coord &obj) {
	coord temp;
	temp.x = i - obj.x;
	temp.y = i - obj.y;
	return temp;
}

int main() {
	coord obj1(6, 6), obj3;
	int x = 5, y;
	obj3 = obj1 - x;
	obj3.get_xy(x, y);
	cout << "(obj1-x) x: " << x << ", y: " << y << "\n";
	y = 3;
	obj3 = y - obj1;
	obj3.get_xy(x, y);
	cout << "(y-obj1) x: " << x << ", y: " << y << "\n";
	return 0;
}
