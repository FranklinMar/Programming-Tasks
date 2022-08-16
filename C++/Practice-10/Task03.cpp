/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: The next class is given. Create custom input and 
  output functions for it.
  
class date {
 char d[9]; // store date as string : mm/dd/yy
public:
// add inserter and extractor
};
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
class date {
  char d[9]; // store date as string : mm/dd/yy
public:
// add inserter and extractor
  friend ostream &operator <<(ostream &o, date &obj);
  friend istream &operator >>(istream &i, date &obj);
};

ostream &operator <<(ostream &o, date &obj) {
	o << "Date MM/DD/YY : " << obj.d << '\n';
	return o;
}

istream &operator >>(istream &i, date &obj) {
	cout << "Enter Date (mm:dd:yy): ";
	i >> obj.d;
	if(obj.d[2] != ':')
		obj.d[2] = ':';
	if(obj.d[5] != ':')
		obj.d[5] = ':';
	return i;
}

int main() {
	date day;
	cin >> day;
	cout << day;
}
