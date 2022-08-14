/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: You have the next class:
  class planet {
   int moons;
   double dist_from_sun; // in miles
   double diameter;
   double mass;
  public:
   // ....
   double get_miles() { return dist_from_sun; }
  };

  Create a light() function that takes an object of planet 
  type as an argument, and which returns the amount of 
  seconds it takes light to reach the planet. (Let's pretend 
  that the speed of light is 186000 miles per second and 
  that the value of dist_from_sun i.e. distance from the Sun, 
  given in miles.).
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class planet {
	int moons;
	double dist_from_sun;
	double diameter;
	double mass;
public:
	void set_planet(int moon, double distance, double diam, double masa);
	double get_miles() { return dist_from_sun; }
};

double light(planet P) {
  double timesec = P.get_miles() / 186000;// time(sec) = Lenght(miles) / speed(miles/sec)
	return timesec;
}

void planet::set_planet(int moon, double distance, double diam, double masa) {
	moons = moon;
	dist_from_sun =  distance;
	diameter = diam;
	mass = masa;
}

int main() {
	planet earth,mars;
	earth.set_planet(1, 92960000, 7917.5, 5.972);// mass= 5.972 * 10^24 kg
	mars.set_planet(2, 147880000, 4212.3, 0.64185);// mass = 6.4185* 10^23 kg
  cout << "The Time (seconds) when light reaches the planet Earth: " << light(earth) << endl;
  cout << "The Time (seconds) when light reaches the planet Mars: " << light(mars) << endl;
	return 0;
}
