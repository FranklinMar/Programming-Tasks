/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Examine the next code:
  #include <iostream >
  using namespace std;
  class mybase {
   int a, b;
  public:
  int c;
   void setab(int i, int j) { a = i; b = j; }
   void getab(int &i, int &j) { i = a; j = b; }
  };
  class derived1 : public mybase {
  // ...
  };
  class derived2 : private mybase {
  // ...
  };
  int main() {
   derived1 obj1;
   derived2 obj2;
   int i, j;
   // ...
  }
  
  Which of the following statements is correct inside the 
  main() function and why?
  
  A) obj1.getab(i, j);
  B) obj2.getab(i, j);
  C) obj1.c = 10;
  D) obj2.c = 10;
------------------------------------------------------------
*/
/*
ANSWER - C 
Firstly - the variable "c" is int type, is the public member
  of the class "mybase".
Secondly - "obj1" object is an instance of "derived1" class 
  and has public access to its parent class members and 
  methods.
A and B answers aren't correct because the member variables 
  weren't initialised, which would cause an error.
D answer is wrong, because it has "private" access to 
  member variables of it's parent class, therefore it can't 
  access the 'c' variable.
*/
