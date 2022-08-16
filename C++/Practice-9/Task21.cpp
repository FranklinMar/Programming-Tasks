/*
------------------
Name: Task21.cpp
------------------------------------------------------------
Description: On the basis of the class created to convert 
  feet to centimeters, write a custom input function that 
  forms an invitation string to write the number of feet. 
  In addition, write a custom output function to display 
  both the number of feet and the number of centimeters 
  on the screen. Include these functions in the program 
  and demonstrate their functionality.
  
class ft_to_cms {
 double feet;
 double cms;
public:
 void set(double f) {
 feet = f;
 cms = f * 30.48;
 }
};

  Hint: 1 ft = 0,3048 m
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class ft_to_cms {
  double feet;
  double cms;
public:
  void set(double f) {
    feet = f;
    cms = f * 30.48;
  }
  friend ostream &operator <<(ostream &stream, ft_to_cms &obj);
  friend istream &operator >>(istream &stream, ft_to_cms &obj);
};
ostream &operator <<(ostream &stream, ft_to_cms &obj) {
	stream << "Feet: " << obj.feet << " | Centimetres: " << obj.cms;
	return stream;
}
istream &operator >>(istream &stream, ft_to_cms &obj) {
	cout << "Enter amount of ft: ";
	stream >> obj.feet;
	obj.cms = obj.feet * 30.48;
	return stream;
}

int main() {
	ft_to_cms object;
	cin >> object;
	cout << object << endl;
	return 0;
}
