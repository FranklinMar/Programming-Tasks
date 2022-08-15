/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: In the snippet below, add a constructor for the 
  "myderived" class. It must pass a pointer of the string to 
  be initialized inside the constructor of the "mybase" class. 
  In addition, the myderived() constructor must initialize 
  the len variable as the length of the string.
  
  #include <iostream>
  #include <cstring>
  using namespace std;
  class mybase {
   char str[80];
  public:
   mybase(char *s); { strcpy (str, s); }
   char *get() { return str; }
  };
  class myderived : public mybase {
   int len;
  public:
   // add myderived() here...
   int getlen() { return len; }
   void show() { cout << get () << '\n'; }
  };
  int main() {
   myderived obо("hello");
   obj.show();
   cout << obj.getlen() << '\n';
   return 0;
  }
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

class mybase {
  char str[80];
public:
  mybase(char *s) { strcpy (str, s); }
  char *get() { return str; }
};

class myderived : public mybase {
  int len;
public:
 // add myderived() here...
  myderived(char *s) : mybase(s) { len = strlen(s); }
  int getlen() { return len; }
  void show() { cout << get () << '\n'; }
};

int main() {
  myderived obj("hello");
  obj.show();
  cout << obj.getlen() << '\n';
  return 0;
}
