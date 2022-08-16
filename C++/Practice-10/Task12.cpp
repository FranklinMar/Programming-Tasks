/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Rewrite the program from Example 10.11 to use 
  the get() function instead of getline(). Will the program 
  work differently?.
------------------------------------------------------------
*/
/* Answer - NO */
#include <iostream>
using namespace std;

int main() {
	char str[80];
	cout << "Enter your name: ";
	bool j = true;
	//cin.getline(str, 79);
	for (int i = 0; i < 79 && j; i++) {
		cin.get(str[i]);
		if (str[i] == '\n' || str[i] == '\0') {
			j = false;
			str[i] = '\0';
		}
	}
	cout << str << '\n';
	return 0;
}
