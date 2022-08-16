/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: Write a program to output a sentence: "I hate C++" 
  in the 30-character width field using a colon (:) as the 
  filler symbol.
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	cout << setw(30) << setfill(':') << "I hate C++" << endl;
	return 0;
}
