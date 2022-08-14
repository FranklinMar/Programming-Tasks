/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Unit 5 "Bounded Array" considered the simplest 
  way to implement safe array, in which array elements were 
  accessed using get() and put() functions. Overloading the 
  [] operator allows you to create such an array much more 
  easier. To create a safe array, implement a control with 
  the operator[]() function borders. In addition, the 
  operator[]() function must return a reference to the 
  indexed element.
  In the fragment below, an attempt was made to add control 
  of the array bounds, which allows generating an appropriate 
  error when the bounds are violated.
  
  Hint: Recall that a safe array is an array, that is 
  encapsulated in class, and at the same time the class 
  provides control over the boundaries of the array. Thanks 
  to overloading of the operator [], you can work with a 
  safe array in the same way as with a normal one.
  
  // A safe array example:
  ...
  class arraytype {
   ...
  };
  // Provide range checking for arraytype .
  int &arraytype::operator [](int i) {
   if (...) {
   cout << "Index value of " << i << " is out of bounds.\n";
   ...
   }
   ...
  }
  int main() {
   arraytype obj;
   // this generates a runtime error because SIZE+100 is out of range:
   obj[SIZE+100] = 99; // error
   return 0;
  }
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class arraytype {
 //...
	int *p;
	int size;
	int n = 0;
public:
	arraytype(int a);
	int & operator [](int a);
};

arraytype::arraytype(int a) {
	if (a <= 0) {
		cout << "size error\n";
		exit(1);
	}
	size = a;
	p = new int[size];
}
// Provide range checking for arraytype .
int &arraytype::operator [](int a) {
 if (a < 0 || a >= size) {
 cout << "Index value of " << a << " is out of bounds.\n";
 //...
 //exit(1);
 return n;
 }
 else
 return p[a];
 //...
}

int main(){
	arraytype A(6);
	//arraytype E(-5);
	for (int i = 0; i < 6; i++) {
		A[i] = i;
	}
	cout << "Array : ";
	for (int i = 0; i < 6; i++) {
		cout << A[i] << ' ';
	}
	cout << endl << A[6] << A[-3];
	return 0;
}
/*
  TIPS
------------------------------------------------------------
  Remember! A secure array increases resource consumption, 
  which is not always acceptable. It is precisely because 
  of the overhead of resources in C ++ (unlike Java) there 
  is no built-in array bounds control. However, in those 
  applications in which it is desirable to provide control 
  of the integrity of the borders, implementing a secure 
  array might be a possible solution.
------------------------------------------------------------
