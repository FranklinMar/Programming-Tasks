/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Create a class to store your name and phone number.
  Using the "new" operator, dynamically allocate memory for 
  an object of this class and enter the name & phone 
  number in the corresponding fields inside the object.
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
using namespace std;

class call{
	char *name;
	long int *number;
public:
	call(char *imya, long int nom);
	void show();
	~call();
};

call::call(char imya[], long int nom) {
	int l = strlen(imya);
	name = new char[l + 1];
	number = new long int;
	strcpy(name, imya);
	*number = nom;
}
call::~call() {
	delete name;
	delete number;
}

void call::show() {
	cout << name;
	cout <<endl << *number << endl; 
}

int main() {
	char name[] = "Denys";
	call callhome(name, 9765656565);
	callhome.show();
	return 0;
}
