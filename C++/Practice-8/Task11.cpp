/*
------------------
Name: Task11.cpp
------------------------------------------------------------
Description: The class hierarchy from Task 07 with the "vehicle" 
  class is given. The program has an error and its code is not 
  formatted. Find the error.
  
  Hint: Try to compile the program, and examine the errors 
  messages.
  
  # include <iostream >
  using namespace std;
  // A base class for various types of vehicles .
  class vehicle
  {
  int num_wheels ;
  int range ;
  public :
  vehicle (int w, int r)
  {
  num_wheels = w;
  range = r;
  }
  void showv ()
  {
  cout << " Wheels : " << num_wheels << '\n'; cout << " Range : " << range << '\n';
  }
  };
  enum motor {gas , electric , diesel };
  class motorized : public vehicle
  {
  enum motor mtr ;
  public :
  motorized ( enum motor m, int w, int r) : vehicle (w, r)
  {
  mtr = m;
  }
  void showm ()
  {
  cout << " Motor : ";
  switch (mtr )
  {
  case gas : cout << "Gas \n";
  break ;
  case electric : cout << " Electric \n";
  break ;
  case diesel : cout << " Diesel \n";
  break ;
  }
  }
  };
  class road_use : public vehicle
  {
  int passengers ;
  public :
  road_use (int p, int w, int r) : vehicle (w, r)
  {
  passengers = p;
  }
  void showr ()
  {
  cout << " Passengers : " << passengers << '\n';
  }
  };
  enum steering { power , rack_pinion , manual };
  class car : public motorized , public road_use
  {
  enum steering strng ;
  public :
  car ( enum steering s, enum motor m, int w, int r, int p) :
  road_use (p, w, r), motorized (m, w, r), vehicle (w, r)
  {
  strng = s; }
  void show () { showv (); showr (); showm (); cout << " Steering : "; switch ( strng ) {
  case power : cout << " Power \n"; break ; case rack_pinion : cout << " Rack and Pinion
  \n";
  break ; case manual : cout << " Manual \n";
  break ; } } }; int main () { car c(power , gas , 4, 500 , 5);
  c. show ();
  return 0;
  }
  
  P.S. When compiling the program, you might see a warning 
  message (or perhaps error message) associated with the use 
  of "switch" statement inside "car" and "motorised" classes. 
  Why?
------------------------------------------------------------
*/
/* 
The error is caused by the "vehicle" class inside its derived
classes, specifically the "car" class. Let's look inside them.
Class "car" has "motorized" and "road_use" as parent classes, 
each of which have the "vehicle" class as their parent class.
And, because of that, the "car" class would create not 1 but 
2 object of "vehicle" class inside the "car" object.
This is what causes the ambigiouty error, because the 
compiler doesn't know which of the instances must be used.

Solution
The solution is pretty simple, just make class "vehicle" as a
virtual class. This will make only 1 instance of the class 
to be created inside the derived class object.

As to the "switch" problem, it's error is most likely caused 
by invalid and awful formatting of the code.
*/
# include <iostream>
using namespace std; 

// A base class for various types of vehicles .
class vehicle {
	int num_wheels;
	int range;
public :
	vehicle(int w, int r) {
		num_wheels = w;
		range = r;
	}
	void showv () {
		cout << " Wheels : " << num_wheels << '\n';
    cout << " Range : " << range << '\n';
	}
};
enum motor {gas, electric, diesel};

class motorized : virtual public vehicle {
	enum motor mtr;
public :
	motorized(enum motor m, int w, int r) : vehicle (w, r) {
		mtr = m;
	}
	void showm () {
		cout << " Motor : ";
		switch (mtr) {
			case gas : cout << "Gas \n";
			break ;
			case electric : cout << " Electric \n";
			break ;
			case diesel : cout << " Diesel \n";
			break ;
		}
	}
};

class road_use : virtual public vehicle {
	int passengers;
public :
	road_use (int p, int w, int r) : vehicle (w, r) {
		passengers = p;
	}
	void showr () {
		cout << " Passengers : " << passengers << '\n';
	}
};

enum steering {power, rack_pinion, manual};

class car : public motorized, public road_use {
	enum steering strng;
public :
	car(enum steering s, enum motor m, int w, int r, int p) : vehicle (w, r), motorized (m, w, r), road_use (p, w, r) {
		strng = s; 
	}
	void show () { 
    showv(); 
    showr(); 
    showm(); 
    cout << " Steering : "; 
		switch (strng) {
			case power : cout << " Power \n"; 
			break ; 
			case rack_pinion : cout << " Rack and Pinion\n";
			break ; 
			case manual : cout << " Manual \n";
			break ; 
		} 
	} 
}; 

int main () { 
	car c(power, gas, 4, 500, 5);
	c.show();
	return 0;
}
