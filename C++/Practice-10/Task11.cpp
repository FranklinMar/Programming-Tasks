/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Given the following class. Write a program to 
  output the content of an object of this class into a file:

  Hint: Create custom output function.
  
class account {
 int custnum;
 char name[80];
 double balance;
public:
 account(int c, char *n, double b) {
 custom = c;
 strcpy(name, n);
 balance = b;
 }
};
------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class account {
  int custnum;
  char name[80];
  double balance;
public:
  account(int c, char *n, double b) {
    custnum = c;
    strcpy(name, n);
    balance = b;
  }
  friend ostream &operator <<(ostream &o, account &obj);
};

ostream &operator <<(ostream &o, account &obj) {
	o << "Cust-num :"<< obj.custnum << " , Name :" << obj.name << " , Balance :" << obj.balance << endl;
	return o;
}

int main() {
	account bank1(201401, "Arkas", 2501);
	account bank2(250101, "Car", 6500);
	ofstream fout("text11.txt");
	if (!fout) {
		cout << "Cannot open text11.txt file.\n";
		return 1;
	}
	fout << bank1 << bank2;
	cout << bank1 << bank2;
	fout.close();
	return 0;
}
