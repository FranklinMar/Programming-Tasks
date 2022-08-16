/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Create the center() function with the following 
  prototype:
  
  void center(char *s);

  This function must place the specified string in the center 
  of the screen. To implement this use the width(). The screen 
  width is assumed to be 80 characters. (For simplicity, consider 
  that the length of a string does not exceed 80 characters.)
  Write a program illustrating the work of this feature.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;

void center(char *s);

int main() {
	center("Hello there!");
	return 0;
}

void center(char *s) {
	int len = strlen(s);
	len = len / 2;
	cout.width(40 + len);
	cout << s << endl;
}
