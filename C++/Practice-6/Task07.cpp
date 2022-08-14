/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Try to compile all programs (see Unit 6,
  "Overloading And Ambiguity"), in which there is an ambiguity. 
  Match compiler messages, explain and remember these error 
  messages. It will help you to immediately recognize ambiguity 
  errors, if they appear in your programs.
------------------------------------------------------------
*/

/*
In these messages, the compiler tells us that it cannot decide 
which function to use. After an error message, the compiler 
shows candidates, namely, functions that are suitable for 
this function call. That is, several functions are suitable 
for this function call at the same time, and the compiler 
cannot decide which function to use for execution.
*/
#include <iostream>
using namespace std;

float f(float t) {
	return t / 2.0;
}
double f(double t) {
	return t / 3.0;
}
int main() {
	float x = 10.09;
	cout << f(x);
	double y = 10.09;
	cout << f(y);
	cout << f(10);
	return 0;
}
/*
void f(unsigned char c){
	cout << c;
}
void f(char c){
	cout << c;
}
int main(){
	f('c');
	f(86);
	return 0;
}
*/
/*
int f(int a, int b) { return a+b; }
int f(int a, int &b) { return a-b; }
int main()
	int x=1, y=2;
	cout << f(x, y);
	return 0;
}
*/
/*
int f(int a) { return a*a; }
int f(int a, int b=0) { return a*b; }
int main() {
	cout << f(10,2);
	cout << f(10);
	return 0;
}
*/
