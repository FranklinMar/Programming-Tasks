/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Create a "who" class. The "who" constructor 
  must have one character argument to be used to identify 
  the object. While creating the object's constructor 
  should display the message: 
  
  Constructing who #x
  
  where x - identification character, unique for each object.
  While deleting the object, it's destructor should display 
  the message: 
  
  Destroying who #x
  
  where x - identification character, unique for each object, 
  again.
  
  Finally, create make_who() function, that returns "who" 
  object. Give each object a unique name. Analyze and 
  explain the result of the program displayed on the screen.
------------------------------------------------------------
*/

/*
Classes work in such a way that when passing some object
to functions as an argument, the object itself is not 
actually passed, but it's exact copy of the same class is 
created and transferred to the function. Therefore, we can 
see that the destructor appears twice, because the object 
in the make_who function and in the main function is free'd.
*/

#include <iostream>
using namespace std;

class who {
	char x;
public:
	who(char const c);
	~who();
};

who :: who(char const c) {
	cout << "Constructing who #" << c << endl; 
	x = c;
}
who :: ~who() {
	cout << "Destroying who #" << x << endl;
}

who make_who() {
	who new_obj('A');
	return new_obj;
}
int main() {
	who ch1('H');
	ch1 = make_who();
	return 0;
}
