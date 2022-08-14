/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Overload the Date() constructor (See Unit 6 
  "Select the most convenient method of initializing an 
  object") so that it has a parameter of type "time_t".
  Hint: Recall that "time_t" is a data type defined by the 
  standard C++ compiler time and date library functions.
------------------------------------------------------------
*/

#include <cstdio>
#include <ctime>
using namespace std;

class Date {
	int day, month, year;
public:
	Date(int m, int d, int y) {
		day = d;
		month = m;
		year = y;
	}
  
	Date(char const *str) {
		sscanf(str, "%d%*c%d%*c%d", &month, &day, &year);
	}
  
	Date(time_t t);
	void show(){
		cout << month << '/' << day << '/' << year << endl;
	}
};

Date :: Date(time_t t) {
	struct tm data = *(localtime(&t));
	day = data.tm_mday;
	month = data.tm_mon;
	year = data.tm_year/* - 100*//*+ 1900*/;
}

int main() {
	Date strdate("25/01/14");
	strdate.show();
	//19.03.19
	Date intdate(18, 06, 20/*19*/);
	intdate.show();
	
	Date time_tdate(time(NULL));
	time_tdate.show();
	return 0;
}
