/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Write a program to count the number of words in 
  a file. For simplicity, consider that a word is everything 
  with two-sided spaces..
------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("text9.txt");
	if (!fin) {
		cout << "Cannot open text9.txt file for reading.\n";
		return 1;
	}
	int wordnum = 0;
	char str[80];
	while (!fin.eof()) {
		fin >> str;
		cout << str << ' ';
		wordnum++;
	}
	fin.close();
	cout << "\nTotal number of words :" << wordnum << '\n';
	return 0;
}
