/*
------------------
Name: Task03.cpp
------------------------------------------------------------
Description: Rewrite Example 5.5 (see Unit 5 "Using Pointers 
  To Objects") so that the contents of the "obj" array were 
  displayed in reverse order.
------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class samp {
	int a, b;
public:
	samp(int n, int m) { a = n; b = m; }
	int get_a() { return a; }
	int get_b() { return b; }
};

int main() {
	samp obj[4] = {samp(1, 2), samp(3, 4),
					samp(5, 6), samp(7, 8)};
	samp *p;
	p = obj + 3;
	for (int i = 0; i < 4; i++) {
		cout << p->get_b() << ' ';
		cout << p->get_a() << "\n";
		p--;
	}
  /* Or Just:
  for (int i = obj + 3; i != obj - 1; i--) {
    cout << i->get_b() << ' ';
    cout << i->get_a() << "\n";
  }
  */
	cout << "\n";
	return 0;
}
