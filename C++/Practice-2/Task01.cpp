/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: Write a program for reading input of hours 
  worked and the size of hourly wage of each employee 
  (personel). After this, print out summary salary of the 
  employees (Check the correctness of input).
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

int main(){
	float salary;
	float cost;
	float hours;
	cout << "Enter the number of Hours worked and the Hourly labour cost\n";
	cout << "Total hours worked:";
	cin >> hours;
	while (hours < 0) {
		cout << "The No. of Hours can't be negative.Please try again.\n";
		cout << "Total hours worked:";
		cin >> hours;
	}
	cout << "\nHourly labour cost (HLC) ($):";
	cin >> cost;
	while (cost < 0) {
		cout << "HLC can't be negative.Please try again.\n";
		cout << "\nHourly labour cost (HLC) ($):";
		cin >> cost;
	}
	salary = cost * hours;
	cout << "\nSalary:" << salary << '$';
	return 0;
}
