/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Create a Dice class that contains a private 
  integer variable. Create a roll() function using the 
  standart random number generator rand(), to get numbers 
  from 1 to 6. Make 5 rolls of four dices. Function roll() 
  must print these values to the screen.
------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Dice {
	int num;
public:
	Dice(int n);
	void roll();
};

Dice :: Dice(int n) {
	num = n;
}

void Dice :: roll() {
	for (int i = 0; i < num; i++)
		cout << rand() % 6 + 1 << ' ';
}

int main() {
	Dice cube(4);
	cout << "Rolling 4 Dices" << endl;
	for (int i = 1; i <= 5; i++) {
		cout << "(Roll " << i << ") ";
		cube.roll();
		cout << endl;
	}
	return 0;
}
