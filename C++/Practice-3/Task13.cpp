/*
------------------
Name: Task13.cpp
------------------------------------------------------------
Description: Using the "stack" class (see Unit 2 "A more 
  practical example"), write loadstack() function, which 
  would return a stack filled with letters of the alphabet 
  (a-z). At caller of the function program, assign this stack 
  to another object and prove that this object contains the 
  alphabet. (Note: Make sure the stack is large enough to
  storage of the alphabet.)
  
  Reload the loadstack() function to take an integer as an 
  argument "upper". In the overloaded version, if the "upper" 
  variable equals to 1, load the stack with uppercase 
  alphabetic characters. Otherwise load it with lower case 
  alphabet characters.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 30

class stack {
	char stck[SIZE];
	int tos;
public:
	void init();
	void push(char ch);
	char pop();
	stack loadstack();
	stack loadstack(int upper);
};

void stack::init() {
	tos = 0;
}
void stack::push(char ch) {
	if (tos == SIZE) {
		cout << "stack is full";
		return ;
	}
	stck[tos] = ch;
	tos++;
}
char stack::pop() {
	if (tos == 0) {
		cout << "Stack is empty";
		return 0;
	}
	tos--;
	return stck[tos];
}

stack stack::loadstack() {
	stack object;
	
	if (SIZE < 26) {
		cout << "Error.Stack size isn't big enough.\n";
		return object;
	}
	int i = 0;
	for (char c = 'a'; c <= 'z'; i++, c++) {
		*(object.stck + i) = c;
	}
	object.tos = 26;
	return object;
}
stack stack::loadstack(int upper) {
	stack object;
	
	if (SIZE < 26) {
		cout << "Error.Stack size isn't big enough.\n";
		return object;
	}
	int i = 0;
	if (upper == 1) {
		for (char c = 'A'; c <= 'Z'; i++, c++) {
			*(object.stck + i) = c;
		}
	} else {
		for(char c = 'a'; c <= 'z'; i++, c++) {
			*(object.stck + i) = c;
		}
	}
	object.tos = 26;
	return object;
}

int main() {
	stack s1, s2;
	int i;
	
	s1.init();
	s2.init();
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s2 = s1.loadstack();
	s1 = s1.loadstack(1);
	for (i = 0; i < 3; i++) 
    cout << "Pop s1:" << s1.pop() << endl;
	for (i = 0; i < 3; i++) 
    cout << "Pop s2:" << s2.pop() << endl;
	
	return 0;
}
