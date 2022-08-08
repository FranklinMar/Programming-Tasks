/*
------------------
Name: Task02.cpp
------------------------------------------------------------
Description: A certain base class is given: 
  class Area {
  public:
  	double height;
  	double width;
  }
  
	Create 2 derived classes Rectangle amd Isosceles, that 
	inherit the base class area. Each calss must include an 
	area() function, that returns the area of rectangle and 
	isosceles triangle respectively.
	To initialize the "height" and "width" variables (the 
	height and length of the base area, respectively) use a 
	constructor with parameters. Add a derived class which 
	inherits the Area class, name this class a Cylinder, and 
	let it calculate the area of cylinder surface. This area 
	is given as follows: 2 * Pi * R * R + Pi * D * height
------------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Area {
public:
	double height;
	double width;
};

class Rectangle: public Area {
public:
	Rectangle(double heigh, double len);
	double area();
};

Rectangle::Rectangle(double heigh, double len) {
	height = heigh;
	width = len;
}

double Rectangle::area() {
	return (height * width);
}

class Isosceles: public Area {
public:
	Isosceles(double heigh, double bottom);
	double area();
};
Isosceles::Isosceles(double heigh, double bottom) {
	height = heigh;
	width = bottom;
}
double Isosceles::area() {
	return (height * width / 2);
}

class Cylinder: public Area {
public:
	Cylinder(double heigh, double radius);
	double area();
};
Cylinder::Cylinder(double heigh, double radius) {
	height = heigh;
	width = radius;
}
double Cylinder::area() {
	double square = 2 * M_PI * width * (width + height);
	return square;
}

int main() {
	Rectangle square(30, 30);
	Isosceles triangle(40, 60);
	Cylinder cylind(50, 10);
	cout << "Rectangle area: " << square.area() << endl;
	cout << "Triangle area: " << triangle.area() << endl;
	cout << "Cylinder area: " << cylind.area() << endl;
	return 0;
}
