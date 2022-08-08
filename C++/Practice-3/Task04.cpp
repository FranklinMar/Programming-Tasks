/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: There are different compilers. Depending on the 
  type of your compiler there may be some restrictions on 
  the use of inline function. For example, some compilers 
  don't treat a function as inline if the function is 
  recursive, or if it contains either a static variable, or 
  any loop execution instruction, or a "switch" statement. 
  You need to write a program, which will help you find out 
  about restrictions on inline functions of your compiler.
  
  Hint: It's a good idea to check your compiler's manual to 
  see exactly defined restrictions on the use of inline 
  functions.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

/*
Modern versions of compilers convert functions into inlines 
automatically. If you won't notice the function as inline, 
compiler will automatically execute it as such, if he 
sees that it will increase it's efficiency. So, in most 
cases there is no need for using keyword "inline".
*/

inline int min(int a) {
	switch(a) {
		case 1:
		cout << a;
		break;
		case 2:
		cout << (-a);
		break;
		default:
		cout << "No";
		break;
	}
	int i = a;
	for(i = a; i < 100; i += a);
	return i;
}
int main() {
	int i = min(3);
	cout << i;
	return 0;
}

