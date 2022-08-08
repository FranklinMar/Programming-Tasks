/*
------------------
Name: Task17.cpp
------------------------------------------------------------
Description: Create a class "time_and_date", which recieves 
  current system time and date as constructor parameters. 
  This class must include a method, that displays the time 
  and date on the screen.
  Hint: use the standart library "ctime" functions.
------------------------------------------------------------
*/
#include <iostream>
#include <ctime>
using namespace std;

class time_and_date {
	time_t tim;
public:
	time_and_date();
	void timeshow();
};

time_and_date :: time_and_date() {
	tim = time(NULL);
}

void time_and_date :: timeshow() {
	cout << "Current Time/Date(Day|Month|Date|Time|Year): " << ctime(&tim) << "\n";
}
int main(){
	time_and_date ob1;
	cout << "Function of showing time\n";
	ob1.timeshow();
	return 0;
}
