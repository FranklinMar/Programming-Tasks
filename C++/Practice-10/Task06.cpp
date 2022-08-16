/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Create a skipchar() input manipulator that reads 
  and passes every 5 input characters in each turn 
  (i.e. "Hello world" => "Hellod").
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string str;

istream &skipchar(istream &in) {
	bool b = true;
	char ch;
	in.unsetf(ios::skipws);
	while(b) {
		for (int i = 0; i < 5 && b; i++) {
			in >> ch;
            if (ch == '\n' || ch == '\0')
				b = false;
			str = str + ch;
		}
		for (int i = 0; i < 5 && b /*&& k < len*/; i++) {
			in >> ch;
			if(ch == '\n' || ch == '\0')
				b = false;
		}
	}
	return in;
}

int main() {
	cout << "Enter something:\n";
	cin >> skipchar;
	cout << str;
	return 0;
}
