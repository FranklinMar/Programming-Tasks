/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: For the class coord (See Unit 7 "Overloading An 
  Operator In Which The Order Of The Operands Is Important") 
  overload the * and / operators. Demonstrate how they work.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	coord operator *(const coord obj);
	coord operator /(const coord obj);
};

coord coord:: operator *(const coord obj) {
	coord temp;
	temp.x = x * obj.x;
	temp.y = y * obj.y;
	return temp;
}

coord coord:: operator /(const coord obj) {
	coord temp;
	temp.x = x / obj.x;
	temp.y = y / obj.y;
	return temp;
}
int main() {
	coord obj1(6, 6), obj2(5, 3),obj3;
	int x, y;
	obj3 = obj1 * obj2;
	obj3.get_xy(x, y);
	cout << "(obj1*obj2) x: " << x << ", y: " << y << "\n";
	obj3 = obj1 / obj2;
	obj3.get_xy(x, y);
	cout << "(obj1/obj2) x: " << x << ", y: " << y << "\n";
	return 0;
}
