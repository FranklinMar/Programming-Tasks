/*
------------------
Name: Task05.cpp
------------------------------------------------------------
Description: Create a class with looped queue of integers 
  (see Unit 2 "A more practical example"). Create a queue 
  with length of 100 integers. Create a short demonstration 
  inside main() function.
  Initialise class instances with the help of constructor.
  
  Hint:
  class q_type {
    int queue[SIZE]; // contains queue
    int head, tail;  // indexes of head an tail
    
  public:
    void init();     // initialisation
    void q(int num); // storing
    int deq();       // retrieving
------------------------------------------------------------
*/
#include <iostream>
using namespace std;
#define SIZE 100

class q_type{
	int queue[SIZE]; 
	int head,tail;
public:
	q_type();
	void init();
	void q(int num);
	int deq();
};

q_type::q_type() {
	cout << "Initializing.\n";
	init();
}
void q_type::init() {
	head = 0;
	tail = 0;
}

void q_type::q(int num) {
	if (tail == SIZE) {
		cout << "Queue is full";
		return;
	}
	queue[tail] = num;
	tail++;
}

int q_type::deq() {
	if (head == tail) {
		cout << "Queue is empty";
		return 0;
	}
	return queue[head++];
}

int main() {
	q_type que1, que2;
	que1.q(1);
	que1.q(2);
	que1.q(3);
	que2.q(98);
	que2.q(99);
	que2.q(100);
	
	for (int i = 0; i < 3; i++) {
		cout << "Queue #1:" << que1.deq() << '\n';
	}
	for (int i = 0; i < 3; i++) {
		cout << "Queue #2:" << que2.deq() << '\n';
	}
	return 0;
}
