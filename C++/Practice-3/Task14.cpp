/*
------------------
Name: Task14.cpp
------------------------------------------------------------
Description: Using the "strtype" class (see Unit 3 Example 
  3.2a), add a friendly function that takes as an argument 
  a pointer to an object of "strtype" class and returns a 
  pointer of a string. (So the function must return 
  pointer "p"). Call this function get_string().
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct strtype {
	strtype(char const *ptr);
	~strtype();
	friend char *get_string(strtype *point);
	void show();
private:
	char *p;
	int len;
};

strtype::strtype(char const *ptr) {
	len = strlen(ptr);
	p = (char *) malloc(len + 1);
	if (!p) {
		cout << "Allocation error.\n";
		exit(1);
	}
	strcpy(p, ptr);
}
strtype::~strtype() {
	cout << "Freeing p\n";
	free(p);
}
void strtype::show() {
	cout << p << " - length : " << len << endl;
}
char *get_string(strtype *point) {
	return point->p;
}

int main() {
	strtype s1("This is a test."),
			s2("I hate any programming!");
	s1.show();
	cout << get_string(&s2) << endl;
	return 0;
}
