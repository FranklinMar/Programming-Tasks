/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Overload the - and / operators for the coord 
  class via friend functions.
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
	friend coord operator -(const coord &obj1, const coord &obj2);
	friend coord operator -(const coord &obj, int i);
	friend coord operator /(const coord &obj1, const coord &obj2);
	friend coord operator /(const coord &obj, int i);
};
coord operator -(const coord &obj1, const coord &obj2){
	coord temp(obj1.x - obj2.x, obj1.y - obj2.y);
	return temp;
}
coord operator -(const coord &obj, int i){
	coord temp(obj.x - i, obj.y - i);
	return temp;
}
coord operator /(const coord &obj1, const coord &obj2){
	coord temp(obj1.x / obj2.x, obj1.y / obj2.y);
	return temp;
}
coord operator /(const coord &obj, int i){
	coord temp(obj.x / i,obj.y / i);
	return temp;
}

int main() {
	coord obj1(6, 6), obj2(5, 3), obj3;
	int x, y;
	int A = 7;
	obj3 = obj1 - obj2;
	obj3.get_xy(x, y);
	cout << "(obj1-obj2) x: " << x << ", y: " << y << "\n";
	obj3 = obj1 / obj2;
	obj3.get_xy(x, y);
	cout << "(obj1/obj2) x: " << x << ", y: " << y << "\n";
	obj3 = obj1 - A;
	obj3.get_xy(x, y);
	cout << "(obj-7) x: " << x << ", y: " << y << "\n";
	obj3 = obj1 / A;
	obj3.get_xy(x, y);
	cout << "(obj1/7) x: " << x << ", y: " << y << "\n";
	return 0;
}
