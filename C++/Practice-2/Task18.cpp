/*
------------------
Name: Task18.cpp
------------------------------------------------------------
Description: Create a class "mybox", that recieves 3 numbers 
  of double type by constructor. They are representing the 
  length of the sides of parallelepiped. Class mybox must
  calculate it's volume and store the result in the double 
  type variable as well. Include a method volume(), that 
  will print on the display the volume of any instance of 
  "mybox" type.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class mybox {
	double volum;
public:
	mybox(double height, double wid, double len);
	void volume();
};

mybox::mybox(double height, double wid, double len){
	volum = height * wid * len;
}

void mybox::volume() {
	cout << "Volume of mybox object: " << volum << "\n";
}

int main() {
	mybox cube(10, 10, 10);
	mybox box(20.5, 10.75, 30.3);
	cout << "Cube:\n";
	cube.volume();
	cout << "Box:\n";
	box.volume();
	return 0;
}
