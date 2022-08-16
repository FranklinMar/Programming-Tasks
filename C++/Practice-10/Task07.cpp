/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Write a program to copy a text file. This program 
  must count the number of characters to be copied and display 
  the result. Why is this number different from the one shown 
  when viewing the directory file list?.
------------------------------------------------------------
*/
/* Because there is additional EOF character, that serves as 
ending of the file */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("text1.txt");
	if (!fin) {
		cout << "Cannot open text1.txt file for reading.\n";
		return 1;
	}
	ofstream fout("text1_a.txt");
	if (!fout) {
		cout << "Cannot open text1_a.txt file for input(writing in).\n";
		return 1;
	}
	char ch;
	int s = 0;
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof()) {
			fout.put(ch);
			cout << ch;
			s++;
		}
	}
	cout << "\nCopied " << s << " characters.\n\n";
  fin.close();
	fout.close();
	return 0;
}
