/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: In the example below, the '%' operator is 
  overloaded incorrectly. Explain, why?
  
  coord coord::operator %(const coord obj) {
   double i;
   cout << "Enter a number: ";
   cin >> i;
   cout << "root of " << i << " is ";
   cout << sqrt(i);
  }
------------------------------------------------------------
*/
/* Answer
------------------------------------------------------------
Because the overloaded operator must return the instance 
(or object) of the class overloaded as a returning value.
------------------------------------------------------------
*/
