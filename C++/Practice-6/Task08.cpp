/*
------------------
Name: Task08.cpp
------------------------------------------------------------
Description: Following are two overloaded functions. Show in
  demo program how to get and how to use the address of each
  them: 
  
  int dif(int a, int b) {
   return a-b;
  }
  float dif(float a, float b) {
   return a-b;
  }
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int dif(int a, int b) {
 return a - b;
}
float dif(float a, float b) {
 return a - b;
}

int main() {
	int (* function1)(int, int);
	float (* function2)(float, float);
	
	function1 = dif;
	int alpha1 = function1(10, 15);
	cout << alpha1 << endl;
	
	function2 = dif;
	float alpha2 = function2(18.5, 0.9);
	cout << alpha2 << endl;
  return 0;
}
