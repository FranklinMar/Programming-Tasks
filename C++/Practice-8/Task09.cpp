/*
------------------
Name: Task09.cpp
------------------------------------------------------------
Description: Create the original "building" base class to hold 
  the number of floors and rooms in building, as well as the 
  total area of the rooms. Create a derived class "house" that 
  inherits class "building" and stores the number of bathrooms 
  and bedrooms. In addition, create a derived "office" class, 
  which inherits the "building" class and stores the number 
  of fire extinguishers and telephones.
------------------------------------------------------------
*/
#include <iostream>
using namespace std; 

class building {
  //protected:
	int floors;
	int rooms;
	double square_area;
public:
	building(int a, int r, double s) { floors = a; /*b*/rooms = r; square_area = s; }
	int get_floors() { return floors; }
	int get_rooms() { return rooms; }
	double get_sqr_area() { return square_area; }
	void showb() {
		cout << "Floors:" << floors << "\nRooms:" << rooms << "\nSquare(area):" << square_area << " m^2\n";
	}
};

class house : public building {
	int bathrooms;
	int bedrooms;
public:
	house(int f, int r, double sq, int bath, int bed) : building(f, r, sq) {
		if ((bath + bed) <= r) {
			bathrooms = bath;
			bedrooms = bed;
		} else {
			cout << "Error.No of bathrooms and bedrooms is bigger than total No of rooms";
			exit(1);
		}
	}
	void showh() {
		showb();
		cout << "Number of bathrooms:" << bathrooms << "\nNumber of bedrooms:" << bedrooms << "\n";
	}
	int get_bath() { return bathrooms; }
	int get_bed() { return bedrooms; }
};

class office : public building {
	int fireextinguishers;
	int phones;
public:
	office(int f, int r, double sq, int fire, int ph) : building(f, r, sq) {
		fireextinguishers = fire;
		phones = ph;
	}
	void showo() {
		showb();
		cout << "Number of extinguishers:" << fireextinguishers << "\nNumber of phones:" << phones << "\n";
	}		
	int get_fire() { return fireextinguishers; }
	int get_phones() { return phones; }
};

int main() {
	house home(9, 5, 46, 1, 2);
	office work(3, 100, 600, 6, 5);
	cout << "Home:\n";
	home.showh();
	cout << "\nWork:\n";
	work.showo();
	return 0;
}
