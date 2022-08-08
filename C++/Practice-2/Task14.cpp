/*
------------------
Name: Task14.cpp
------------------------------------------------------------
Description: Create a class "stopwatch" to simulate a
  stopwatch. Use constructor for initial stopwatch setting 
  to 0. Create 2 methods - start() and stop() respectively 
  for launching and stopping the stopwatch. Include show() 
  method inside your class too, for displaying on the screen 
  the current time, elapsed from the moment of creating 
  a class instance of "stopwatch" till it's deletion.
  (Measure it in seconds)
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class stopwatch {
	clock_t start;
	clock_t stop;
public:
	stopwatch();
	void startf();
	void show();
	void stopf();
	~stopwatch();
};

stopwatch :: stopwatch() {
	start = 0;
}

void stopwatch :: startf () {
	cout << "Starting secondmeter.\n";
	start = clock();
}

void stopwatch :: show() {
	cout << "Current time: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds.\n";
	clock();
}
void stopwatch :: stopf() {
	stop = clock();
}

stopwatch :: ~stopwatch() {
	clock_t end;
	end = clock();
	cout << "Elapsed time: " << ((end - start) / CLOCKS_PER_SEC) << " seconds.\n";
}

int main() {
	stopwatch ob;
	char c;
	ob.startf();
	cout << "Hello,this is a time function.\n";
	ob.show();
	for(int i = 0; i < 1000000000 ; i++);
	return 0;
}
