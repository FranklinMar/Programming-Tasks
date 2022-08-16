/*
------------------
Name: Task15.cpp
------------------------------------------------------------
Description: Write a program to display the contents of the 
  text file in reverse order.
------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin("text15.txt");
	if (!fin) {
		cout << "Cannot open text15.txt file for reading.\n";
		return 1;
	}
	int s = 0;
	fin.seekg(0, ios::end);
	s = fin.tellg();// Defining cursor current position inside the file from its beginning
	fin.seekg(1, ios::beg);
	char ch;
	for (int i = 1; s > 0; s--, i++) {
		fin.seekg(-i, ios::end);
		ch = fin.peek();
        cout << ch;
	}
	cout << endl;
	return 0;
}
