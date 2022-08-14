/*
------------------
Name: Task14.cpp
------------------------------------------------------------
Description: In Unit 2, a program was created with the 
  "strtype" class, in which the memory for the string is 
  allocated dynamically. Modify this program so the "new" 
  and "delete" operators were used.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 255

class strtype {
	char *p;
	int len;
public:
	strtype();
	~strtype();
	void set(char const *ptr);
	void show();
};

strtype :: strtype() {
	p = new char[SIZE];
	if (!p) {
		cout << "Allocation error.\n";
		exit(1);
	}
	*p = '\0';
	len = 0;
}

strtype :: ~strtype() {
	cout << "Freeing p\n";
	delete [] p;
}

void strtype::set(char const *ptr) {
	if (strlen(ptr) > SIZE) {
		cout << "String too big\n";
		return;
	}
	strcpy(p, ptr);
	len = strlen(p);
}

void strtype::show() {
	cout << p << "- length : " << len;
	cout << "\n";
}

int main() {
	strtype s1, s2;
	s1.set("This is a test.");
	s2.set("I like C++.");
	
	s1.show();
	s2.show();
  return 0;
}
