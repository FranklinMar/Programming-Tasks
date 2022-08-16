/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Modify the Tasks 07 and 09 to use get(), put(), 
  read() and/or write() functions. Think and use these 
  features where you think they will do the biggest benefit.
------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("text10.txt");
	if (!fin) {
		cout << "Cannot open text10.txt file for reading.\n";
		return 1;
	}
	ofstream fout("text10_a.txt");
	if (!fout) {
		cout << "Cannot open text10_a.txt file for input(writing in).\n";
		return 1;
	}
	char ch;
	int s = 0;
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof()) {
			fout << ch;
			cout << ch;
			s++;
		}
	}
	cout << "\nCopied " << s << " characters.\n\n";
	fin.close();
	fout.close();
	fin.open("text10_a.txt");
	int wordnum = 0;
	fin.seekg(0, ios::beg);// Перемiщуємо вказiвник в початок файлу
	while (!fin.eof()) {
		fin.get(ch);
        if (ch == ' ' || fin.eof()) {
            wordnum++;
        }
    }
	fin.close();
	cout << "\nTotal number of words :" << wordnum << '\n';
	return 0;
}
