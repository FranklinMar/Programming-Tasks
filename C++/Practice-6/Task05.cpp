/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: In the C++ standard library, there is a strtol() 
  function that has the following prototype:
  
  long strtoi(const char *start, const **end, int base);
  
  The function converts the string with number written inside, 
  where "start" is the pointer refering, to the long integer. 
  The "base" variable specifies the base of the number system. 
  When the function returns its value, the end pointer refers 
  to the address of the character, which is located right 
  after the last digit of the number in the string.
  
  The returning long integer value is equivalent to the 
  number written inside the string.
  
  However, mostly, the base of the number system is 10.
  Create a mystrtol() function that works exactly like the 
  strtol() function, but the argument 10 should be passed to 
  base by default. The strtol() function is allowed to be 
  freely used for the actual transformations. To do this, 
  you will need to include the <cstdlib> header in the program.
  Show that your version works correctly.
------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
using namespace std;
long mystrtol(const char *start,char **end, int base = 10){
	return strtol(start, end, base);
}

int main(){
	char *end;
	char strin[] = "6.50 Hello world!";
	cout << mystrtol(strin, &end);
	cout << endl << *end << endl;
	cout << mystrtol(strin, &end, 30);
	return 0;
}
