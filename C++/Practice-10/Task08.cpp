/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Write a program to write to the file "phones.txt" 
  of the following data type:
  
- Ivan Tormozenko, +38067 415 5113
- Petro Siplusenko, +38068 212 5332
- Olena Kompailenko, +38050 202 54517.
------------------------------------------------------------
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("phones.txt");
	if (!fout) {
		cout << "Cannot open phones.txt as output file.\n";
		return 1;
	}
	char number1[] = "Ivan Tormozenko, +38067 415 5113",
	number2[] = "Petro Siplusenko, +38068 212 5332",
	number3[] = "Olena Kompailenko, +38050 202 54517";
	fout << number1 << /*'\n'*/'\n' << number2 << /*'\n'*/ '\n' << number3;
	fout.close();
	ifstream fin("phones.txt");
	if (!fin) {
		cout << "Cannot open phones.txt as input file.\n";
		return 1;
	}
	char ch;
	while (!fin.eof()) {
		fin.get(ch);
		if (!fin.eof())
			cout << ch;
	}
	fin.close();
	return 0;
}
