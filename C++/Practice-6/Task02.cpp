/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: In Unit 2 (see file Pract02.pdf, Task 2.14) you 
  have created a simulation of stopwatch. Modify your 
  solution so that the "stopwatch" class would contain a 
  parameterless constructor (as already done) and its 
  overloaded version for access to the system time via the 
  standard clock() "ctime" function. Show that the changes 
  you made are working. 
  
  Advice from Lecturer: Think about how overloaded 
  constructor can be useful for your own program tasks, for 
  example, in course work (term paper?).
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class stopwatch{
	clock_t start;
	clock_t stop;
public:
	stopwatch();
	stopwatch(int starttime);
	void startf();
	void show();
	void stopf();
	~stopwatch();
};

stopwatch :: stopwatch() {
	start = 0;
}
stopwatch :: stopwatch(int starttime) {
	start = starttime;
}
void stopwatch :: startf() {
	cout << "Starting secondmeter.\n";
	start = clock();
}

void stopwatch :: show() { cout << "Current time: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds.\n";
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
	ob.startf();
	cout << "Hello,this is a time function.\n";
	ob.show();
	for (int i = 0; i < 1000000000; i++);
	return 0;
}
