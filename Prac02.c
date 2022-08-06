#include <stdio.h>
#include <string.h> // Завдання 'с'. Підключає бібліотеку з функцією strlen()
#define Q "His Hamlet was funny without being vulgar." // Завдання 'с'
int main(void) {
	printf("He sold the painting for $%2.2f. \n", 2.345e2); // Завдання 'a'
	printf("%c%c%c\n",'H', 105, '\41'); // Завдання 'b'
	printf("' %s '\nhas %ld characters.\n", Q, strlen(Q)); // Завдання 'c'
	printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0); // Завдання 'd'
	return 0;
}