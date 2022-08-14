/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Modify this program so that it uses "new" 
  operator:
  
  char *p;
  p = (char *)malloc(100);
  // ...
  strcpy(p, " This is a test.");
  
  Hint: String = character array.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char *p;
	p = new char[100];
	strcpy(p, " This is a test.");
	cout << p;
	return 0;
}
