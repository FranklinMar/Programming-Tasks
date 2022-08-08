/*
------------------
Name: Task15.cpp
------------------------------------------------------------
Description: Create a new version of the previously 
  developed strtype class, in which a constructor with a 
  parameter is used (see Unit 2 "An Example that Shows the 
  Need for Both a Constructor and a Destructor Function"). 
  In your version of the strtype class, the string gets its 
  own initial value using the constructor.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define SIZE 255

class strtype {
	char *p;
	int len;
public:
	strtype(char const *ptr);
	~strtype();
	void show();
};

strtype :: strtype(char const *ptr) {
	p = (char *) malloc (SIZE);
	if (!p) {
		cout << "Allocation error.\n";
		exit(1);
	}
	if (strlen(ptr) > SIZE) {
		cout << "String too big\n";
		exit(1);
	}
	strcpy(p, ptr);
	len = strlen(p);
}

strtype :: ~strtype() {
	cout << "Freeing p\n";
	free(p);
}
void strtype::show() {
	cout << p << "- length : " << len;
	cout << "\n";
}

int main() {
	strtype s1("This is a test."), s2("I like C++.");
	s1.show();
	s2.show();
}
