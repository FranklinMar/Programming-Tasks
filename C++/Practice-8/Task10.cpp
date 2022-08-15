/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Given the following program snippet, fill in the 
  details as indicated in the comments:
  
  #include <iostream>
  using namespace std;
  class planet {
  protected:
   double distance ; // miles from the sun
   int revolve ; // in days
  public:
   planet(double d, int r) { distance = d; revolve = r; }
  };
  class earth : public planet {
   double circumference; // circumference(окружность) of orbit
  public:
   /* Create earth(double d, int r). Have it pass the distance and days of revolution back
  to planet.
   Have it compute the circumference of the orbit. (Hint: circumference = 2r *3.1416.)
  */
   /* Create a function called show() that displays the information.*!/
  };
  int main() {
   earth obj(93000000, 365);
   obj.show();
   return 0;
  }
------------------------------------------------------------
*/
#include <iostream>
//#include <cmath>
using namespace std;

class planet {
protected:
  double distance ; // miles from the sun
  int revolve ; // in days
public:
  planet(double d, int r) { distance = d; revolve = r; }
};
class earth : public planet {
  double circumference; // circumference(окружность) of orbit
public: 
  earth(double d, int r) : planet(d, r) { circumference = 2 * d * 3.1416 /*M_PI*/; }
 /* Create earth(double d, int r). Have it pass the distance and days of revolution back
to planet.
 Have it compute the circumference of the orbit. (Hint: circumference = 2r *3.1416.)
*/
 void show() {
	 //cout << "Planet Earth\n";
	 cout << "Distance:" << distance << " m\n" << "Revolve:" << revolve << " days\n" << "Circumference of orbit:" << circumference << " m\n";
 }
 /* Create a function called show() that displays the information.*/
};

int main() {
 earth obj(93000000, 365);
 obj.show();
 return 0;
}
