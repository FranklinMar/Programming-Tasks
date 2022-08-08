/*
------------------
Name: Task16.cpp
------------------------------------------------------------
Description: Modift the stack class (see Unit 2 "An Improved 
  Version of the Stack class") so that memory for the stack 
  would be allocated dynamically. At the same time, the 
  length of the stack must be specified as a constructor 
  parameter. (Don't forget to release this memory with the 
  destructor!)
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class stack{
	char *stck;
	int tos;
	int size;
public:
	stack(int s);
	void push(char ch);
	char pop();
	~stack();
};

stack :: stack(int s) {
	cout << "Constructing a stack\n";
	size = s;
	stck = (char *) malloc(size);
	tos = 0;
}

stack :: ~stack() {
	cout << "Destructing a stack\n";
	free(stck);
}
void stack :: push(char ch) {
	if (tos == size) {
		cout << "stack is full\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}
char stack :: pop() {
	if (tos == 0) {
		cout << "Stack is empty\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

int main() {
	stack s1(10),s2(10);
	int i;
	s1.push('a');
	s2.push('x');
	s1.push('b');
	s2.push('y');
	s1.push('c');
	s2.push('z');
	for (i = 0; i < 3; i++)
		cout << "Pop s1: " << s1.pop() << "\n";
	for (i = 0; i < 3; i++)
		cout << "Pop s2: " << s2.pop() << "\n";
	return 0;
}
