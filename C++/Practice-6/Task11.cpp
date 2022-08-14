/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Create an order() function that takes two 
  integer reference parameters. If the first argument is 
  greater than the second, swap their values. Otherwise, you 
  don't have to do anything. Thus, the order of the two 
  arguments used when calling the order() function must 
  be such that always after the function returned its value, 
  the first argument was less second. For example, if given:
  
  int x=1, y=0;
  order(x, y);
  
  then, after the call of function, x = 0 and y = 1.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

void order(int &i, int &j) {
	if (i > j) {
		int t = i;
		i = j;
		j = t;
	}
}

int main() {
	int A = 1;
	int B = 0;
	cout << "A:" << A << " B:" << B << endl;
	order(A, B);
	cout << "A:" << A << " B:" << B << endl;
	return 0;
}
