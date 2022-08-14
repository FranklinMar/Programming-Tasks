/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Overload the '+' operator with respect to the 
  coord class both binary and unary versions (See Unit 7 
  "Overloading A Unary Operator"). At used as a unary 
  operator + must make positive the value of any negative 
  coordinate.
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
	coord operator +(const coord &obj);
	coord operator +();
};

coord coord:: operator +(const coord &obj){
	coord temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}
coord coord:: operator +(){
	coord temp;
	temp.x = (x > 0) ? x : -x;
	temp.y = (y > 0) ? y : -y;
	return temp;
}

int main() {
	coord obj1(6, 6), obj2(-5, 3), obj3;
	int x, y;
	obj3 = obj1 + obj2;
	obj3.get_xy(x, y);
	cout << "(obj1+obj2) x: " << x << ", y: " << y << "\n";
	obj3 = +obj2;
	obj3.get_xy(x, y);
	cout << "(+obj2) x: " << x << ", y: " << y << "\n";
	return 0;
}
