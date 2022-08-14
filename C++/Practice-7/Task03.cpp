/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: Experiment by changing the return type of 
  operator functions to something other than coord. Pay 
  attention to the generated error message compiler. Explain 
  the reasons for the errors.
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
	int operator +(const coord obj);
};
int coord:: operator +(const coord obj) {
	int a;
	a = x + y + obj.x + obj.y;
	return a;
}

int main() {
	coord obj1(6, 6), obj2(5, 3);
	int A;
	A = obj1 + obj2;
	cout << "A : " << A << "\n";
	return 0;
}
/*
The reason of errors lies inside the following sample of code.
It is because the result of the function is assigned to 
absolutely different type of data inside the "main" function:
int main(){
	...
	char bad = obj1 + obj2;
	...
}
*/
