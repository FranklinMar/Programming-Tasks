/*
------------------
Name: Task04.cpp
------------------------------------------------------------
Description: Create class "card", that will support the 
  catalog of library cards. This class must contain the name 
  of the book, name of the author and the number of books 
  instances issued. Name of the book and name of the author, 
  should be stored as string of characters, and the number 
  of instances - as integer number. Use public function-
  -member (method) store() for storing information about the 
  books and method show() for displaying information on the 
  screen. Create a short demonstration inside main() function.
------------------------------------------------------------
*/

#include <iostream>
#include <cstring>
using namespace std;

class card{
	char name[50];
	char author[50];
	int num;
public:
	void store(char book[50], char aname[50], int exem);
	void show();
};
void card::store(char book[50], char aname[50], int exem){

	strcpy(name, book);
	strcpy(author, aname);
	num = exem;
}
void card::show(){
	cout << "Name of the book:" << name;
	cout << "\nName of the author:" << author;
	cout << "\nNumber of copies:" << num << '\n';
}
int main(){
	card custom1, custom2;
	char text1[50] = "The Mysterious Island";
	char text2[50] = "Rita Hayworth and Shawshank Redemption";
	char author1[50] = "Jules Verne";
	char author2[50] = "Stephen King";
	custom1.store(text1, author1, 2);
	custom2.store(text2, author2, 3);
	cout << "Card 1\n";
	custom1.show();
	cout << "Card 2\n";
	custom2.show();
	return 0;
}
