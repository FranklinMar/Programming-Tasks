/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: Write a program for converting meters into feet 
  and feet into inches. Read the number of meters as input 
  and printing into the console the amount of feet and 
  inches. Repeat this algorithm until user won't enter '0' 
  as the amount of meters.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
	float meters = 1;
	float feet;
	float inch;
	while (meters != 0) {
    cout << "Converting meters into feet and inches.\nEnter the no. of meters:";
    cin >> meters;// 1m == 3.28084 ft
    feet = meters / 0.3048;// 1ft == 0.3048 m
    inch = feet * 12;// 1 ft == 12 ''
    cout << "Num of meters:" << meters;
    cout << "\nNum of feet:" << feet;
    cout << "\nNum of inches:" << inch << '\n';
	}
	return 0;
}
