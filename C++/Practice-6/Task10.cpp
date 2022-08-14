/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Create a reverse() function with two parameters. 
  First parameter stris a pointer to a string whose character 
  order, after return function of its value, must be reversed. 
  Second the count parameter specifies the number of characters 
  permuted in the string str. Meaning count by default should 
  be such that if it is not set, the function reverse() 
  reversed the order of characters in an entire string.
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *str, int count = -1) {
	if (count < 0) {
		count = strlen(str);
	}
	char strin[count];
	for (int i = 0; i < count; i++) {
		*(strin + i) = *(str + i);
	}
	int j = count - 1;
	for (int i = 0; i < count; i++, j--) {
		*(str + i) = *(strin + j);
	}
}
int main() {
	char name[] = "Hello there";
	cout << name << endl;
	reverse(name, 5);
	cout << name << endl;
	/*reverse(name);
	cout << name << endl;*/
	return 0;
}
