/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Add a custom input function to the "strtype" 
  class of Task 09.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
  char *p;
  int len;
public:
  strtype(char *ptr);
  ~strtype() { delete [] p; }
  friend ostream &operator <<(ostream &stream, strtype &obj);
  friend istream &operator >>(istream &stream, strtype &obj);
};

istream &operator >>(istream &stream, strtype &obj) {
	stream >> obj.p;
	return stream;
}
strtype::strtype(char *ptr) {
  len = strlen(ptr)+1;
  p = new char(len);
  if (!p) {
    cout << "Allocation error\n";
    exit(1);
  }
  strcpy(p, ptr);
}
// Create operator << inserter function here.
ostream &operator <<(ostream &stream, strtype &obj){
	stream << obj.p /*<< " , " << obj.len*/;
	return stream;
}

int main() {
 strtype s1("This is a test."), s2("I hate C++!");
 cout << s1 << '\n' << s2 << '\n';
 cin >> s1;
 cout << s1 << '\n';
 return 0;
}
