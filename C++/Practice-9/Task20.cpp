/*
------------------
Name: Task20.cpp
------------------------------------------------------------
Description: Write a program with the "watch" class, which 
  would play the role of ordinary clock. Using standard time 
  functions, create a class constructor that should read and 
  store system time. To display time on the display, create 
  a custom output function.
------------------------------------------------------------
*/
#include <iostream>
#include <Windows.h>
using namespace std;

class watch {
	int sec;
	int min;
	int hour;
public:
	watch(time_t t) {
		struct tm &data = *(localtime(&t));
		sec = data.tm_sec;
		min = data.tm_min;
		hour = data.tm_hour;
	}
	void set(time_t t) {
		struct tm &data = *(localtime(&t));
		sec = data.tm_sec;
		min = data.tm_min;
		hour = data.tm_hour;
	}
	friend ostream &operator <<(ostream &stream, watch &obj);
};
ostream &operator <<(ostream &stream, watch &obj) {
	stream.width(2);
	stream.fill('0');
	stream << obj.hour << ':';
	stream.width(2);
	stream.fill('0');
	stream << obj.min << ':';
	stream.width(2);
	stream.fill('0');
	stream << obj.sec << endl << endl;
	return stream;
}

int main() {
	watch timenow(time(0));
	for (int i = 0; i < 5; ++i) {
		timenow.set(time(0));
		cout << timenow;
		Sleep(2000);
	}
	return 0;
}
