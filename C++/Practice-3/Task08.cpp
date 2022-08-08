/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Using the "stack" class (see Unit 3 Example 3.7)
  add a function to the program showstack(), which takes an 
  object of type "stack" as an argument. This function 
  should print the contents of the stack to the screen.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
#define SIZE 10

class stack {
	char stck[SIZE];
	int tos;
public:
	stack();
	void push(char ch);
	char pop();
};

void showstack(stack s) {
	char c;
	cout << "\nShowing stack\n";
	for(int i = 1; (c = s.pop()) != 0; i++)
		cout << "("<<i<<") " << c << endl;
}

stack::stack() {
	cout << "Constructing a stack\n";
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

int main() {
	stack s1,s2;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s2 = s1;
	showstack(s1);
	showstack(s2);
	return 0;
}
