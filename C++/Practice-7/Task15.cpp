/*
------------------
Name: Task15.cpp
------------------------------------------------------------
Description: You were given a class definition: 
  class three_d {
   int x, y, z;
  public:
   three_d(int i, int j, int k) { x=i; y=j; z=k; }
   three_d(){ x=0; y=0; z=0; }
   void get(int &i, int &j, int &k) { i=x; j=y; k=z; }
  };
  Overload the '+', '-', '++', and '--' operators for this 
  class. For the "increment" and "decrement" operators o
  verload only prefix or only postfix form.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class three_d {
 int x, y, z;
public:
 three_d(int i, int j, int k) { x = i; y = j; z = k; }
 three_d(){ x = 0; y = 0; z = 0; }
 void get(int &i, int &j, int &k) { i = x; j = y; k = z; }
 three_d operator +(const three_d obj);
 three_d operator -(const three_d obj);
 three_d operator ++(int notused);
 three_d operator --(int notused);
};
three_d three_d::operator +(const three_d obj) {
	three_d temp(x + obj.x, y + obj.y, z + obj.z);
	return temp;
}
three_d three_d::operator -(const three_d obj) {
	three_d temp(x - obj.x, y - obj.y, z - obj.z);
	return temp;
}
three_d three_d::operator ++(int notused) {
	x++;
	y++;
	z++;
	return *this;
}
three_d three_d::operator --(int notused) {
	x--;
	y--;
	z--;
	return *this;
}

int main() {
	three_d obj1(6, 7, 6), obj2(5, 3, 7), obj3;
	int x, y, z;
	obj3 = obj1 + obj2;
	obj3.get(x, y, z);
	cout << "(obj1+obj2) x: " << x << ", y: " << y << ", z: " << z << "\n";
	obj3 = obj1 - obj2;
	obj3.get(x, y, z);
	cout << "(obj1-obj2) x: " << x << ", y: " << y << ", z: " << z << "\n";
	obj1++;
	obj1.get(x, y, z);
	cout << "(obj1++) x: " << x << ", y: " << y << ", z: " << z << "\n";
	obj1--;
	obj1.get(x, y, z);
	cout << "(obj1--) x: " << x << ", y: " << y << ", z: " << z << "\n";
	return 0;
}
