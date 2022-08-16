/*
------------------
Name: Task18.cpp
------------------------------------------------------------
Description: Create a "box" class to store the size of the 
  square. To display a square image, create a custom output 
  function. (Choose any display method).
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;

class box {
	int side;
public:
	box(int s = 0) {
		side = s;
	}
	void schange(int n) { side = n; }
	friend ostream &operator <<(ostream &stream, box &obj);
	
};
ostream &operator <<(ostream &stream, box &obj) {
	stream << setw(obj.side + 1) << setfill('*') << "\n";
	for (int i = 0; i < obj.side - 2; i++) {
		stream << '|' << setw(obj.side - 1) << setfill(' ') << '|' << endl;
	}
	if (obj.side > 1) {
		stream << setw(obj.side+1) << setfill('*') << "\n";
	}
	return stream;
}

int main() {
	box square1(5);
	cout << square1;
	square1.schange(1);
	cout << endl << square1;
	square1.schange(2);
	cout << endl << square1;
	square1.schange(3);
	cout << endl << square1;
	square1.schange(4);
	cout << endl << square1;
	return 0;
}
