/*
------------------
Name: Task12.cpp
------------------------------------------------------------
Description: Write a program that creates a bounded (safe) 
  two-dimensional (2x3) array of integers. Show how it works.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

class array {
	int **aint;
	int height;
	int width;
public:
	array(int h, int w);
	~array() { delete [] aint; }
	int &insert(int i, int j);
	int get(int i, int j);
};

array::array(int h, int w) {
	height = h;
	width = w;
	aint = new int*[height];
	for (int i = 0; i < height; i++)
		aint[i] = new int[width];
	if (!aint) {
		cout << "Allocation error \n";
		exit(1);
	}
}

int &array::insert(int i, int j) {
	if (i < 0 || i >= height || j < 0 || j >= width) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return *(*(aint + j) + i);
}

int array::get(int i, int j) {
	if (i < 0 || i >= height || j < 0 || j >= width) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return *(*(aint + j) + i);
}

int main() {
	array a(2, 3);
	cout << "Filling up 2x3 array:\n";
	int ar = 1;
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) {
			a.insert(i, j) = ar;
			cout << ar << " ";
			ar++;
		}
		cout << endl;
	}
	cout << "Showing array:\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a.get(i, j) << " ";
		}
		cout << endl;
	}
	cout << a.get(0, 3) << " ";
	return 0;
}
