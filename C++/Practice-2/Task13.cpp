/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Create function rev_str() for changing the 
  order of characters in the string to the reverse.
  Overload rev_str(), so it could be called with 1 or 2 
  strings. If the function is called with 1 string, then the 
  operation must be done on it. If it is called with 2 strings, 
  the result string must be contained in the second argument.
  (look Unit 2 "Overloaded functions that differ in the number
  of their arguments").
  Example:
  char s1[80], s2[80];
  strcpy(s1, "hello");
  rev_str(s1, s2); // reversed string goes in s2, s1 is untouched
  rev_str(s1);     // reversed string is returned in s1
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

void rev_str (char *string){
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++) {
		char temp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = temp;
	}
}
void rev_str (const char *string1, char *string2){
	int len = strlen(string1);
	for (int i = 0; i < len; i++) {
		string2[len - i - 1] = string1[i];
	}
}

int main() {
	char string[20] = "Hello";
	char strange[20];
	strcpy(strange, string);
	char *strp = &string[0];
	rev_str(strp);
	cout << string << '\n';
	rev_str(string, strange);
	cout << string << ' ' << strange << '\n';
	return 0;
}
