/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Given the following class declaration, add 
  whatever is necessary for creating a dynamic array type. 
  That is, allocate memory for the array and store pointer 
  to this memory at ptr. Store the size of the array in bytes 
  in a variable size. Create a put() function that returns a 
  reference to the given array element and a get() function 
  that returns the value of the given element. Get in control 
  of array bounds. Also, overload the assignment operator so 
  that the memory allocated to each array of this type was 
  not accidentally corrupted during assigning one array to 
  another.
  
  class dynarray {
   int *ptr;
   int size;
  public:
   dynarray(int s); // pass size of array in s
   int &put(int i); // return reference to element i
   int get(int i); // return value of element i
   // create operator =() function
  };
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class dynarray {
 int *ptr;
 int size;
public:
 dynarray(int s); // pass size of array in s
 int &put(int i); // return reference to element i
 int get(int i); // return value of element i
 dynarray operator =(dynarray &obj);
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
}

int main() {
	dynarray A(5);
	int n = 6;
	for (int i = 0; i < 5; i++) {
		A.put(i) = n--;
	}
	cout << "Array <A>:";
	for (int i = 0; i < 5; i++) {
		cout << A.get(i) << ' ';
	}
	cout << endl << A.get(6) << endl;
	dynarray a(-5);
	a = A;
	cout << "Array <a>:";
	for (int i = 0; i < 5; i++) {
		cout << a.get(i) << ' ';
	}
	return 0;
}
