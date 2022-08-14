/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Explain why the following program ends with a 
  message "Aborted (core dumped)" and fix it:
  
  #include <iostream>
  #include <cstdlib>
  using namespace std;
  class myсlass {
   int *ptr;
  public:
   myclass(int i);
   ~myсlass() { delete ptr; }
   friend int getval(myclass obj);
  };
  myclass::myсlass(int i) {
   ptr = new int;
   if (!ptr) { exit(1); }
   *ptr = i;
  }
  int getval(myclass obj) {
   return *obj.ptr; // get value
  }
  int main() {
   myclass a(1), b(2);
   cout << getval(a) << " " << getval(b) << "\n";
   cout << getval(a) << " " << getval(b);
   return 0;
  }
------------------------------------------------------------
*/
/*
"Aborted (core dumped)" is happening, because the method 
getval() recieves not the object itself, but it's temporary 
copy. However, the address inside "ptr" pointer is the same. 
Therefore, when we go to the address of "ptr" pointer, and 
return the value from the function, the destructor is called 
that uses "delete" operator on ptr pointer.
Then, after the second call of the same function getval() 
we are trying to go to the address of "ptr" pointer, and 
get value from it, but the memory of the address was 
already free'd, which causes the error.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class myclass {
 int *ptr;
public:
 myclass(int i);
 ~myclass() { delete ptr; }
 friend int getval(const myclass &obj);
};
myclass :: myclass(int i) {
 ptr = new int;
 if (!ptr) { exit(1); }
 *ptr = i;
}
int getval(const myclass &obj) {
 return *obj.ptr; // get value
}
int main() {
 myclass a(1), b(2);
 cout << getval(a) << " " << getval(b) << "\n";
 cout << getval(a) << " " << getval(b);
 return 0;
}
