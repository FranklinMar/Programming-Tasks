/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: Using the following class declaration, create 
  an array of 10 elements and initialize the variable "ch" 
  with values from A to J. Show that the array actually 
  contains those values.
  
  #include <iostream>
  using namespace std;
  class letters {
   char ch;
  public:
   letters(char c) { ch = c; }
   char get_ch() { return ch; }
  };
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class letters {
 char ch;
public:
 letters(char c) { ch = c; }
 char get_ch() { return ch; }
};

int main() {
	letters alphabet[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	cout << "Showing array:";
	for (int i = 0; i < 10; i++) {
		cout << alphabet[i].get_ch() << ' ';
	}
	return 0;
}
