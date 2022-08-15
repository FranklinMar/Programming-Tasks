/*
------------------
Name: Task16.cpp
------------------------------------------------------------
Description: Modify your solution to Problem 7.15, so that 
  operator-functions would use reference parameters instead 
  of value parameters.
  Overload the operators '==', '!=', '||' and '+' of the class 
  "three_d" of Problem 7.15 so it's objects would be able to 
  perform the following types of operations:
  
  obj + int;
  int + obj;
  
  Hint: The increment and decrement operators require friendly
  functions.
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
 three_d operator +(const three_d &obj);
 three_d operator -(const three_d &obj);
 friend three_d operator ++(three_d &obj, int notused);
 friend three_d operator --(three_d &obj, int notused);
 friend int operator ==(three_d &obj1, three_d &obj2);
 friend int operator !=(three_d &obj1, three_d &obj2);
 friend int operator ||(three_d &obj1, three_d &obj2);
 friend three_d operator +(three_d &obj, int i);
 friend three_d operator +(int i, three_d &obj);
};
three_d three_d::operator +(const three_d &obj) {
	three_d temp(x + obj.x, y + obj.y, z + obj.z);
	return temp;
}
three_d three_d::operator -(const three_d &obj) {
	three_d temp(x - obj.x, y - obj.y, z - obj.z);
	return temp;
}
three_d operator ++(three_d &obj,int notused) {
	obj.x++;
	obj.y++;
	obj.z++;
	return obj;
}
three_d operator --(three_d &obj,int notused) {
	obj.x--;
	obj.y--;
	obj.z--;
	return obj;
}
int operator ==(three_d &obj1, three_d &obj2) {
	/*if (obj1.x == obj2.x && obj1.y == obj2.y && obj1.z == obj2.z) { 
		return 1;
	}
	return 0;*/
  return obj1.x == obj2.x && obj1.y == obj2.y && obj1.z == obj2.z;
}
int operator !=(three_d &obj1, three_d &obj2) {
	/*if (obj1.x != obj2.x && obj1.y != obj2.y &&o bj1.z != obj2.z) {
		return 1;
	}
	return 0;*/
  return obj1.x != obj2.x && obj1.y != obj2.y &&o bj1.z != obj2.z;
}
int operator ||(three_d &obj1, three_d &obj2) {
	/*if (obj1.x || obj2.x || obj1.y || obj2.y || obj1.z || obj2.z) {
		return 1;
	}
	return 0;*/
  return obj1.x || obj2.x || obj1.y || obj2.y || obj1.z || obj2.z;
}
three_d operator +(three_d &obj, int i) {
	three_d temp(obj.x + i, obj.y + i, obj.z + i);
	return temp;
}
three_d operator +(int i, three_d &obj) {
	three_d temp(obj.x + i, obj.y + i, obj.z + i);
	return temp;
}

int main() {
	three_d obj1(6, 6, 7), obj2(5, 3, 7), obj3;
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
	obj3 = obj1 + 7;
	obj3.get(x, y, z);
	cout << "(obj1+7) x: " << x << ", y: " << y << ", z: " << z << "\n";
	obj3 = 7 + obj1;
	obj3.get(x, y, z);
	cout << "(7+obj1) x: " << x << ", y: " << y << ", z: " << z << "\n";
	return 0;
}
