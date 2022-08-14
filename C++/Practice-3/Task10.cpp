/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Come up with an example of a program in which, 
  as in the case of an incorrect deleting object (freeing 
  dynamic memory), returning an object from a function would 
  also cause an error.
------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class object {
	char *p;
public:
	object(char c);
	~object();
	char *get_adr();
};

object::object(char c) {
	cout << "Construct\n";
	p = (char *) malloc(sizeof(char));
	*p = c;
}

// THIS WOULD CAUSE AN ERROR LATER
object::~object() {
	//free(p);
}
char *object::get_adr() {
	return p;
}

object *ret_class(object obj) {
	object temp('n');
	char *cptr = obj.get_adr();
	char *ptr = obj.get_adr();
	free(cptr);
	free(ptr);
	object *optr = &temp;
	return optr;
}

int main() {
	object obj('b');
	char *ptr;
	ptr = obj.get_adr();
	cout << ptr << endl;
	object *obj0 = ret_class(obj);
	ptr = obj0->get_adr();
	cout << ptr << endl;
  // ERROR HERE
	//free(ptr);
	return 0;
}
