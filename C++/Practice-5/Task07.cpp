/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: In the new version of the program Example 5.11 
  (see Unit 5 "More About new And delete") add a destructor 
  and make sure (demonstrate in program) that when freeing 
  the memory indicated by the ptr pointer, for each element 
  of the array (once for each element of the array) the 
  destructor is being called.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class samp {
	int i, j;
public:
	void set_ij(int a, int b){ i = a; j = b; }
	int get_product() { return i * j; }
	~samp();
};

samp::~samp() {
	cout << "Destructing " << i << endl;
}

int main() {
	samp *ptr;
	ptr = new samp [10];
	for (int i = 0; i < 10; i++)
		ptr[i].set_ij(i, i);
  
	for (int i = 0; i < 10; i++) {
		cout << "Product [" << i << "] is: ";
		cout << ptr[i].get_product() << "\n";
	}
	delete [] ptr;
	return 0;
}
