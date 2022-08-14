/*
------------------
Name: Task15.cpp
------------------------------------------------------------
Description: Do an experiment: if an object of a derived 
  class is assigned to another object of the same derived 
  class, will the data, related to the base class, also be 
  copied? To find the answer, use the following two classes 
  and write a program.
  
  class base {
   int a;
  public:
   void load_a(int n) { a = n; }
   int get_a() { return a; }
  };
  class derived: public base {
   int b;
  public:
   void load_b(int n) { b = n; }
   int get_b() { return b; }
  };
------------------------------------------------------------
*/
/*
------------------------------------------------------------
Answer: Yes.
------------------------------------------------------------
*/


#include <iostream>
using namespace std;

class base {
	int a;
public:
	void load_a(int n) { a = n; }
	int get_a() { return a; }
};

class derived: public base {
	int b;
public:
	void load_b(int n) { b = n; }
	int get_b() { return b; }
};

int main() {
	derived c1, c2;
	c1.load_a(5);
	c1.load_b(8);
	c2 = c1;
	cout << "Class 2: a - "<< c2.get_a() << "; b - " << c2.get_b() << endl; 
	if (c2.get_a() == c1.get_a())
		cout << "Yes" << endl;
	return 0;
}
