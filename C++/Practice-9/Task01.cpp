/*
------------------
Name: Task01.cpp
------------------------------------------------------------
Description: Create a class hierarchy to store aircraft 
  information devices. Start with a common "Airship" base 
  class designed for storage the number of passengers carried 
  and the amount of cargo carried in pounds or kilograms or 
  tons. Then create two derivatives of the "Airship" class: 
  "Airplane" and "Balloon"(airship). The "Airplane" class must 
  store the aircraft engine type (propeller or jet) and range 
  in miles or kilometers. The "Balloon" class must store 
  information about the type of gas used to lift the airship 
  (hydrogen or helium), and its maximum ceiling (in feet or 
  meters). Create a program for demonstrating how this class 
  hierarchy works.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class Airship {
	int passengers;
	double weight_t;
public:
	Airship(int p, double w) { 
		passengers = p;
		weight_t = w;
	}
	void showAir() {
		cout << "Passengers: " << passengers << "\nCargo weight(Ton.): " << weight_t << endl;
	}
	
};

enum engine {rotor, jet};

class Airplane : public Airship {
	enum engine plane;
	double range_kilo;
public:
	Airplane(enum engine m, double r, int p, double w) : Airship(p, w) {
		range_kilo = r;
		plane = m;
	}
	void showplane() {
		showAir();
		cout << "Engine: ";
		if (plane == rotor) {
			cout << "Rotor";
		} else {
			cout << "Jet";
		}
		cout << "\nFlight range(Kilom.): " << range_kilo << endl;
	}
};

enum gas {hydrogen, helium};

class Balloon : public Airship {
	enum gas ball;
	double upper_limit;
public:
	Balloon(enum gas t, double l, int p, double w) : Airship(p, w) {
		ball = t;
		upper_limit = l;
	}
	void showballoon() {
		showAir();
		cout << "Gas (type): ";
		if (ball == hydrogen) {
			cout << "Hydrogen";
		} else {
			cout << "Helium";
		}
		cout << "\nUpper limit(Meter): " << upper_limit << endl;
	}
};

int main() {
	Airplane A_25(jet, 2014, 2, 6);
	Balloon Fly(hydrogen, 251, 25, 100);
	cout << "A-25 plane\n";
	A_25.showplane();
	cout << "Fly balloon\n";
	Fly.showballoon();
	return 0;
}
