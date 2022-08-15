/*
------------------
Name: Task17.cpp
------------------------------------------------------------
Description: Create your own version of the strtype class 
  that would allow the following types operations:
  • String concatenation using the '+' operator;
  • Assigning strings with the '=' operator;
  • String comparison using '<', '>', and '==' operators.
  Fixed length strings are allowed. At first glance, this may
  seem like a daunting task, but with a little thought and 
  experimentation, you will definitely do it..
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
	strtype(int bytes);
	strtype(char *strin ,int bytes);
	char *getstring() { return p; }	
	int getlength() { return len; }
	//char *operator =() { return p; }
	friend strtype operator +(strtype &obj1, strtype &obj2);
	strtype operator =(strtype obj);
	friend int operator >(strtype &obj1, strtype &obj2);
	friend int operator ==(strtype &obj1, strtype &obj2);
	friend int operator <(strtype &obj1, strtype &obj2);
};
strtype :: strtype() {
	p = new char[255];
	if (!p) {
		cout << "Allocation error \n";
		exit(1);
	}
	len = 255;
}
strtype :: strtype(int bytes) {
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
}
strtype :: strtype(char *strin, int bytes) {
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
	/*
	if(strlen(strin) > len){
		cout << "Bounds error!\n";
		exit(1);
	}*/
	/*if ((int) strlen(strin) < len) {
		for (int i = 0; i < (int)strlen(strin); i++) {
			*(p + i) = *(strin + i);
		}	
	} else {
		for (int i = 0; i < len; i++) {
			*(p + i) = *(strin + i);
		}
	}*/
	len = (int) strlen(strin) < len ? (int) strlen(strin) : len;
	for (int i = 0; i < len; i++) {
		*(p + i) = *(strin + i);
	}
}
strtype operator +(strtype &obj1, strtype &obj2) {
	int len1 = strlen(obj1.p);
	int len2 = strlen(obj2.p);
	strtype temp(len1 + len2);
	strcpy(temp.p, obj1.p);
	strcpy(temp.p + len1,obj2.p);
	
	return temp;
}
strtype strtype:: operator =(strtype obj) { 
	len = obj.len; 
	p = new char[len];
	if (!p) {
		cout << "Allocation error \n";
		exit(1);
	}
	for (int i = 0; i < obj.len; i++) {
		*(p + i) = *(obj.p + i);
	}
	return *this; 
}
int operator >(strtype &obj1, strtype &obj2) {
	/*if (strcmp(obj1.p, obj2.p) > 0) {
		return 1;
	}
	return 0;*/
  return strcmp(obj1.p, obj2.p) > 0;
}
int operator ==(strtype &obj1, strtype &obj2) {
	/*if (strcmp(obj1.p, obj2.p) == 0) {
		return 1;
	}
	return 0;*/
  return strcmp(obj1.p, obj2.p) == 0;
}
int operator <(strtype &obj1, strtype &obj2) {
	/*if (strcmp(obj1.p, obj2.p) < 0) {
		return 1;
	}
	return 0;*/
  return strcmp(obj1.p, obj2.p) < 0;
}

int main() {
	strtype strin1("Some stuff...", 20);
	strtype strin2("This is a test.", 16);
	strtype obj;
	obj = strin1 + strin2; 
	cout << strin1.getstring() << endl;
	cout << strin2.getstring() << endl;
	cout << obj.getstring() << endl;
	obj = strin1;
	cout << obj.getstring() << endl;
	cout << (strin1 > strin2) << "\n";
	cout << (strin1 == strin2) << "\n";
	cout << (strin1 < strin2) << "\n";
	return 0;
}
