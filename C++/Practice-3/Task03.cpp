/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: Use a union to swap high (left) and low (right) 
  bytes of an int.
  Hint: your computer probably uses a 64-bit integer.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

union swape {
	int b;
	swape(int n);
	void swap();
	unsigned char c[sizeof(int)];
	void show();
};
swape :: swape(int n) {
	b = n;
}

void swape :: swap() {
	unsigned char temp = c[1];
	c[1] = c[0];
	c[0] = temp;
}

void swape :: show() {
	cout << b;
}

int main() {
	swape integer(1);
	cout << "Integer before: ";
	integer.show();
	integer.swap();
	cout << "\nInteger after: ";
	integer.show();
	return 0;
}
