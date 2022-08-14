/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Modify Example 5.3 (see Unit 5 "Arrays of 
  objects") so that you could access an element from 
  two-dimensional array through a pointer. 
  
  Hint: in C++, as in C, all arrays are stored contiguous, 
  from left to right, from the lowest element to senior.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class samp {
	int a;
public:
	samp(int n) { a = n;}
	int get_a() { return a; }
};

int main() {
	samp obj [4][2] = { 1, 2,
						3, 4,
						5, 6,
						7, 8};
	samp *p;
	p = &obj[0][0];
	for (int i = 0; i < 4; i++) {
		cout << (p + i)->get_a() << ' ';
		cout << (p + i + 1)->get_a() << endl;
		p++;
	}
	cout << endl;
	return 0;
}
