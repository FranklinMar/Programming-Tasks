/*
------------------
Name: Task19.cpp
------------------------------------------------------------
Description: Use the "stack" class shown here to create a 
  custom output function to insert into the stack content 
  stream. Show that the function is working.
  
#include <iostream>
using namespace std;
#define SIZE 10
class stack {
 char stck[SIZE]; // holds the stack
 int tos; // index of top -of - stack
public:
 stack();
 void push(char ch); // push character on stack
 char pop(); // pop character from stack
};
// Initialize the stack:
stack::stack() {
 tos = 0;
}
// Push a character
void stack::push (char ch) {
 if (tos == SIZE) {
 cout << "Stack is full\n";
 return 0;
 }
 stck[tos] = ch;
 tos++;
}
// Pop a character:
char stack::pop() {
 if (tos==0) {
 cout << "Stack is empty\n";
 return 0;
 }
 tos--;
 return stck[tos];
}
------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 10
class stack {
  char stck[SIZE]; // holds the stack
  int tos; // index of top -of - stack
public:
  stack();
  void push(char ch); // push character on stack
  char pop(); // pop character from stack
  friend ostream &operator <<(ostream &stream, stack &obj);
};
ostream &operator <<(ostream &stream, stack &obj){
	//stream << "<top>";
	for (int i = obj.tos; i >= 0; i--)
		stream << setw(3) << obj.stck[i] << '\n';
	//stream << "<bottom>" << '\n';
	//stream << endl << endl;
	return stream;
}
// Initialize the stack:
stack::stack() {
  tos = 0;
}
// Push a character
void stack::push (char ch) {
  if (tos == SIZE) {
    cout << "Stack is full\n";
    return ;
  }
  stck[tos] = ch;
  tos++;
}
// Pop a character:
char stack::pop() {
  if (tos == 0) {
    cout << "Stack is empty\n";
    return 0;
  }
  tos--;
  return stck[tos];
}

int main() {
	char string[6] = "ereht";
	stack str;
	for (int i = 0; i < 5; i++)
		str.push(string[i]);
	cout << str ;
	for (int i = 0; i < 5; i++)
		str.pop();
	for (int i = 'a'; i < 'g'; i++)
		str.push(i);
	cout << str ;
	return 0;
}
