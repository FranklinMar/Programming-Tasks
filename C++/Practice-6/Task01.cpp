/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: An incomplete class definition is given:

  class strtype {
   char *p;
   int len;
  public:
   char *getstring() { return p; }
   int getlength() { return len; }
  };
  
  Add two constructors to this definition. The first one 
  shouldn't have parameters. It must allocate 255 bytes of 
  memory (using the "new" operator), initialize this memory 
  with a zero string and set the variable "len" equal to 255. 
  The second constructor should have two parameters. The first 
  one is the string used during initialization, the second is 
  the number of bytes to allocate. In the second version, the 
  constructor it must allocate the specified amount of memory, 
  which should contain a copy of the string. It is necessary 
  to implement a complete control of array bounds 
  (Hint: see Unit 5) and, to develop in a short output 
  program, which shows that both constructors work as they 
  were intended to.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

class strtype {
	char *p;
	int len;
public:
	strtype();
	strtype(char *strin ,int bytes);
	char *getstring() { return p; }	
	int getlength() { return len; }
};
strtype :: strtype() {
	p = new char[255];
	if (!p) {
		cout << "Allocation error \n";
		exit(1);
	}
	//*p = NULL;
	len = 255;
}

strtype :: strtype(char *strin ,int bytes) {
	if (bytes <= 0) {
		cout << "Initialiation error\n";
		exit(1);
	}
	p = new char[bytes];
	len = bytes;
	if (!p) {
		cout << "Allocation error \n";
		exit(1);
	}
	if ((int) strlen(strin) < len)
		for (int i = 0; i < (int) strlen(strin); i++)
			*(p + i) = *(strin + i);		
	else
		for (int i = 0; i < len; i++)
			*(p + i) = *(strin + i);
}

int main() {
	strtype strin1;
	strtype strin2("This is a test.", 16);
	
	char *p = strin1.getstring();
	strcpy(p, "Some stuff...");
	cout << strin1.getstring() << endl;
	cout << strin2.getstring() << endl;
	return 0;
}
