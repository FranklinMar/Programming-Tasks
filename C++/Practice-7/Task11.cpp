/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Compare the strtype implementation using the 
  copy constructor (See Unit 6 "Copy Constructor To Allow 
  Objects To Be Passed To Functions", and strtype implementation,
  using a reference as a parameter and a reference as a return
  function values (See Unit 7 "A Closer Look At The Assignment 
  Operator"). Explain what one solution is better than the 
  other.
  
  Hint: As you learned from Unit 6, making a copy 
  constructor is another way solutions to the problems 
  described in Unit 7. The copy constructor may not be so 
  effective solution like link as parameter + link as return 
  value of the function. This is because using the link 
  eliminates the resource cost associated with copying an 
  object in each of the two the indicated cases. In C++, there 
  are often multiple ways to achieve the same goals. Understanding 
  their advantages and disadvantages is part of the process 
  of your becoming a professional C++ programmer.
------------------------------------------------------------
*/

#include <iostream>
using namespace std; 
class dynarray {
 int *ptr;
 int size;
public:
 dynarray(int s); // pass size of array in s
 dynarray(const dynarray &obj);
 int &put(int i); // return reference to element i
 int get(int i); // return value of element i
 //dynarray operator =(dynarray &obj);
 // create operator =() function
};
dynarray :: dynarray(int s) {
	if (s <= 0) {
		cout << "\nInitialising array Error.Creating 2-element array instead\n";
		size = 2;
		ptr = new int[2];
	} else {
		size = s;
		ptr = new int[size];
	}
}
dynarray :: dynarray(const dynarray &obj) {
	cout << "\nCopy that\n";
	ptr = new int[obj.size];
	size = obj.size;
	for (int i = 0; i < size; i++)
		ptr[i] = obj.ptr[i];
}
int &dynarray::put(int i) {
	if (i < 0 || i >= size) {
		cout << "\nOut of bounds Error.Returning first element reference\n";
		return ptr[0];
	}
	return ptr[i];
}
int dynarray::get(int i) {
	if (i < 0 || i >= size) {
		cout << "\nOut of bound Error.Returning first element\n";
		return ptr[0];
	}
	return ptr[i];
}
/*
dynarray dynarray::operator =(dynarray &obj) {
	if (size < obj.size) {
		//cout << "\n size Error.Increasing array size\n";
		delete [] ptr;
		ptr = new int[obj.size];
		size = obj.size;
	}
	for (int i = 0; i < size; i++)
		ptr[i] = obj.ptr[i];
	return *this;
}*/
dynarray somefunc(dynarray obj) {
	dynarray temp = obj;
	cout << "some action";
	return temp;
}
int main() {
	dynarray obj(6);
	dynarray obj1 = somefunc(obj);
	obj1 = obj;
	return 0;
}
