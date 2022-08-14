/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Given the following incomplete class declaration, 
  add constructors so that both declarations in the main() 
  function are correct.
  Hint: you need to overload the samp() constructor twice.
  
  class samp {
   int a;
  public:
   // add constructor functions
   int get_a() { return a; }
  };
  int main() {
   samp obj(88); // init obj a to 88
   samp objarray[10]; // non - initialized 10-element array
   // ...
  }
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class samp {
 int a;
public:
 samp(){;}
 samp(int A){ a = A; }
 int get_a() { return a; }
};

int main() {
 samp obj(88); // init obj a to 88
 samp objarray[10]; // non - initialized 10-element array
 cout << obj.get_a() << endl;
 /*for (int i = 0; i < 10; i++)
	 objarray[i].set_a() = i;
 
 for (int i = 0; i < 10; i++)
	 cout << objarray[i].get_a();*/
 return 0;
}
