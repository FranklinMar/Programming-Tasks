/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: The copy constructor is also called when the 
  function generates temporary object used as its return 
  value (for those functions that return objects). Knowing 
  this, consider the following program output:
  
  Constructing normally
  Constructing normally
  Constructing copy
  Constructing copy
  
  These output string are the result of the following 
  program:
  
  #include <iostream>
  using namespace std;
  class myclass {
  public:
   myclass();
   myclass(const myclass &obj);
   myclass f();
   myclass g(myclass obj);
  };
  // Normal constructor
  myclass::myclass() {
   cout << "Constructing normally\n";
  }
  // Copy constructor
  myclass::myclass(const myclass &obj) {
   cout << "Constructing copy\n";
  }
  // Return an object.
  myclass myclass::f() {
   myclass temp;
   return temp;
  }
  myclass myclass::g(myclass obj) {
   myclass temp = obj;
   return temp;
  }
  int main() {
   myclass obj;
   obj = obj.f();
   obj = obj.g(obj);
   return 0;
  }
  
  Explain, what is going on in there, and why?
------------------------------------------------------------
*/

/*
ANSWER
------------------------------------------------------------
During (initialization) creation, the main function uses a 
normal constructor without parameters. Then, we go to the 
obj.f() method, where the temp object is also created by a 
normal constructor without parameters. Next, we return to 
the "main" function, where we pass the object as a 
parameter to the obj.g() function. By passing to the "g" 
method and simultaneously passing it an object as a 
parameter, we are actually creating and simultaneously 
initializing an object with the help of the copy 
constructor a copy of the transferred object.
Next, in the same "g" function, we create the temp object 
and immediately initialize it to the obj object, so the 
copy constructor is used.
------------------------------------------------------------
*/
