/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: Create you own function sleep() that stops 
  the program from running for the number of seconds 
  specified in the argument. Overload sleep(), so it could 
  be called with an int or string with an int inside.
  For example, the next 2 expression must make the program 
  stop from running for 10 seconds:
  sleep(10);
  sleep("10");
  Demonstrate the work of the program.
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

void sleep(int sec) {
	clock_t start = clock();
	while(clock() < sec * CLK_TCK);
}
int parseInt(char* chars);

void sleep(char *sec) {
	int time = parseInt(sec);
	clock_t start = clock();
	while(clock() < time * CLK_TCK);
}
int powInt(int x, int y) {
    for (int i = 0; i < y; i++) {
        x *= 10;
    }
    return x;
}

int parseInt(char* chars) {
    int sum = 0;
    int len = strlen(chars);
    for (int x = 0; x < len; x++) {
        int n = chars[len - (x + 1)] - '0';
        sum = sum + powInt(n, x);
    }
    return sum;
}

int main() {
	cout << "start of waiting\n";
	sleep(10);
	cout << "end of waiting\n";
	cout << "start of waiting\n";
	sleep("10");
	cout << "end of waiting\n";
	return 0;
}
