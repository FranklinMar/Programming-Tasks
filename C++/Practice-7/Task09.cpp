/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: From the Unit 7 material, you should have 
  understood that with the help of a friendly operator-functions, 
  you can tell the difference between prefix and postfix 
  forms of the increment and decrement operators in exactly 
  the same way, as it was done with using member functions 
  (simply add an integer parameter when setting postfix 
  version). For example, here are the prefix and postfix 
  versions increment operator with respect to class coord :
  
  coord operator ++(coord &obj); // prefix
  coord operator ++(coord &obj, int notused); // postfix
  
  If the ++ operator is before the operand, then the coord 
  operator ++(coord &obj) function is called. If the ++ 
  operator is after the operand, the coord function is called
  operator ++(coord&obj, int notused). In this case, the 
  notused variable would be passed value 0. Come up with 
  your own example (and class too), demonstrating all of the 
  above.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class character {
	char A;
public:
	character(char a){ A = a; }
	character(){ ; }
	char get(){ return A; }
	//character operator =(const character &obj);
	friend character operator ++(character &obj);
	friend character operator ++(character &obj, int notused);
};

/*
character character::operator =(const character &obj) {
	character temp(obj.A);
	return temp;
}
*/
character operator ++(character &obj) { 
	obj.A = obj.A + 1;
	return obj;
}
character operator ++(character &obj, int notused) { 
	obj.A = obj.A + 1;
	return obj;
}

int main() {
	character obj1('A'), obj2;
	char N;
	N = obj1.get();
	cout << "(obj1) A: " << N << endl;
	obj2 = obj1++;
	N = obj2.get();
	cout << "(obj1++) A: " << N << endl;
	obj2 = obj1++;
	N = obj2.get();
	cout << "(++obj1) A: " << N << endl;
	return 0;
}
