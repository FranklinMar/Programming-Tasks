/*
------------------
Name: Task07.cpp
------------------------------------------------------------
Description: Explain, why the code below works:

#include <cstdlib>
#include <iostream>
using namespace std;

int main (int argc, char **argv) {
  cout << argv[argc-1] << endl
  << argc[argv-1] << endl;
  return EXIT_SUCCESS;
}
------------------------------------------------------------
*/
/*
Answer:
This works, because argv parameter points out on the same 
address of memory cell.

The thing is, that compiler sees expression "argv[argc-1]"
as " *(argv + argc - 1)". And if we convert the next 
expression "argc[argv-1]" the same way, we will get 
" *(argc + argv -1)". Meaning "argv[argc-1]" = "argc[argv-1]"

*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main (int argc, char **argv) {
  cout << argv[argc-1] << endl
  << argc[argv-1] << endl;
  return EXIT_SUCCESS;
}
