/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Modify your solution to Problem 7.12 to use the 
  [] operator for indexing a dynamic array. That is, replace 
  the get() and put() functions with operator [].
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
	char *ptr;
	int len;
public:
	strtype(char const *s);
	~strtype() {
		cout << " Freeing ptr\n";
		delete [] ptr;
	}
	char *get() { return ptr; }
	strtype & operator =(const strtype &obj);
	char & operator [](int i);
};

strtype::strtype(char const *s) {
	int len = strlen(s) + 1;
	ptr = new char[len];
	if (!ptr) {
		cout << "Allocation error\n";
		exit(1);
	}
	this->len = len;
	strcpy(ptr, s);
}
strtype & strtype :: operator =(const strtype &obj) {
	if (len < obj.len) {
		delete [] ptr;
		ptr = new char[obj.len];
		if (!ptr) {
			cout << "Allocation error\n";
			exit(1);
		}
	}
	len = obj.len;
	strcpy(ptr, obj.ptr);
	return *this;
}
char & strtype :: operator [](int i) {
	if (i < 0 || i >= len) {
		return ptr[0];
	}
	return ptr[i];
}

int main() {
	strtype a("Hello"), b("Goodbye");
	cout << a.get() << '\n';
	cout << b.get() << '\n';
	a = b;
	b[0] = a[1];
	cout << a[0] << '\n';
	cout << b[0] << '\n';
	return 0;
}
