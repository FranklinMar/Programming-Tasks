/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Using the following class hierarchy, create a 
  constructor for class "C" in such a way, that it would 
  initialize the variable "k" and pass arguments to the 
  constructors A() and B().
  
  #include <iostream >
  using namespace std;
  class A {
   int i;
  public:
   A(int a) { i = a; }
  };
  classB {
   int j;
  public:
   B(int a) { j = a; }
  };
  class C : public A, public B {
   int k;
  public:
   /* Create C() so that it initializes k and passes arguments to both A() and B() *!/
  };

------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class A {
  int i;
public:
  A(int a) { i = a; }
};
class B {
  int j;
public:
  B(int a) { j = a; }
};
class C : public A, public B {
  int k;
public:
  C(int a, int b, int c) : A(a), B(b) { k = c; }
  /* Create C() so that it initializes k and passes arguments to both A() and B() */
};

int main() {
 C obj(6, 7, 5);
 return 0;
}
