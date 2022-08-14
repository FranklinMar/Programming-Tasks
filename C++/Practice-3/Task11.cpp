/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Imagine a situation where the two classes shown 
  below, pr1 and pr2, share only one printer. For the rest of 
  the program, you need to know when the printer is occupied 
  by an object of one of these classes. Create an inuse() 
  function that returns true when the printer is occupied by 
  an object of one of the classes and false otherwise case. 
  Make this function friendly to both pr1 and pr2.
  
  class pr1 {
   int printing;
   // ...
  public:
   pr1() { printing = 0; }
   void set_print(int status) { printing = status; }
   // ...
  };
  
  class pr2 {
   int printing;
   // ...
  public:
   void set_print(int status) { printing = status; }
   // ...
  };
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class pr1 {
	int printing;
public:
	pr1() { printing = 0; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pr1 object1);
};

class pr2 {
	int printing;
public:
	void set_print(int status) { printing = status; }
	friend bool inuse(pr2 object2);
};

bool inuse(pr1 object1) {
	if (object1.printing)
		return true;
	return false;
}

bool inuse(pr2 object2) {
	if (object2.printing)
		return true;
	return false;
}

int main() {
	pr1 print1;
	pr2 print2;
	print2.set_print(0);
	if (inuse(print1) == false) {
		print2.set_print(1);
		cout << "Printing 2\n";
	}
	if (inuse(print2) == false) {
		print1.set_print(1);
		cout << "Printing 1\n";
	} else {
		print2.set_print(0);
		print1.set_print(1);
		cout << "Printing 1\n";
	}
	if (inuse(print2))
		print2.set_print(0);
	return 0;
}
