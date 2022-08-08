/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Modify the stack class (see Unit 2 "A more 
  practical example") so that in class, where possible, 
  inline functions were used.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
#define SIZE 10

class stack {
	char stck[SIZE];
	int tos;
public:
	void init();
	void push(char ch);
	char pop();
};

inline void stack::init() {
	tos = 0;
}

inline void stack::push(char ch) {
	if(tos == SIZE) {
		cout << "stack is full";
		return ;
	}
	stck[tos] = ch;
	tos++;
}

inline char stack::pop() {
	return (tos == 0) ? 0 : stck[--tos];
}

int main() {
	stack s1, s2;
	int i;
	
	s1.init();
	s2.init();
	
	s1.push('a');
	s2.push('x');
	s1.push('b');
	s2.push('y');
	s1.push('c');
	s2.push('z');
	
	for (i = 0; i < 3; i++) cout << "Pop s1:" << s1.pop() << endl;
	for (i = 0; i < 3; i++) cout << "Pop s2:" << s2.pop() << endl;
	
	return 0;
}
