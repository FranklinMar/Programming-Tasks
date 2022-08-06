/*
--------------
Name: Task03.c
--------------
Description: Write a program, that: 
- asks for the name of user;
- asks for the age of user, after printing the name;
- adds constant to the age and prints it back.
--------------
*/
#include <stdio.h>
#define B "booboo"
#define X 10
int main(void) {
	int age;
	char name[40];
	printf("Please enter your first name.\n");
	scanf("%s", name);
	printf(	"All right, %s, what's your age?\n", name);
	scanf("%d", &age);
	int xp = age + X;
	printf("That's a %s! You must be at least %d.\n", B, xp);
	return 0;
}
