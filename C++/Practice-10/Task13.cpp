/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Write a program to read the text file line by line 
  and display each line on the screen. Use the getline() 
  function.
------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "ERROR. write: Task13.exe <FILENAME>" << endl;
		return 0;
	}
	ifstream fin(argv[1]);
	if (!fin) {
		cout << "Cannot open " << argv[1] << " file for reading.\n";
		return 1;
	}
	string strcloud;
	while (!fin.eof()) {
		getline(fin, strcloud);
		cout << strcloud << endl;
	}
	fin.close();
	return 0;
}
