/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Rewrite the coord class so that you can use 
  objects like coord to multiply each of the coordinates 
  by an integer. Both must be correct the following instructions: 
  obj * int and int * obj.
  Explain why the solution requires using friendly 
  operator-functions. Show how with friend function operator 
  overload operator - relative to class coord. Define both 
  prefix and postfix forms.
------------------------------------------------------------
*/
/*
The "friend" functions must be used in order to overload 
operators, because overloaded operator inside the class 
must have 1 and only parameter or argument, and that is 
the instance of the same class.
*/
#include <iostream>
using namespace std;

class coord {
	int x, y;
public:
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	friend coord operator *(const coord &obj, int i);
	friend coord operator *(int i, const coord &obj);
	friend coord operator -(const coord &obj, int i);
	friend coord operator -(int i, const coord &obj);
};
coord operator *(const coord &obj, int i) {
	coord temp(obj.x * i, obj.y * i);
	return temp;
}

coord operator *(int i, const coord &obj) {
	coord temp(obj.x * i, obj.y * i);
	return temp;
}
coord operator -(const coord &obj, int i){
	coord temp(obj.x - i, obj.y - i);
	return temp;
}
coord operator -(int i, const coord &obj){
	coord temp(i - obj.x, i - obj.y);
	return temp;
}
int main() {
	coord obj1(6, 6), obj3;
	int A=5;
	int x, y;
	obj3 = obj1 * A;
	obj3.get_xy(x, y);
	cout << "(obj1*A) x: " << x << ", y: " << y << "\n";
	obj3 = A * obj1;
	obj3.get_xy(x, y);
	cout << "(A*obj2) x: " << x << ", y: " << y << "\n";
	obj3 = obj1 - A;
	obj3.get_xy(x, y);
	cout << "(obj1-A) x: " << x << ", y: " << y << "\n";
	obj3 = A - obj1;
	obj3.get_xy(x, y);
	cout << "(A-obj1) x: " << x << ", y: " << y << "\n";
	return 0;
}
