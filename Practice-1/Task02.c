/*
--------------
Name: Task02.c
--------------
Description: Write a program, that completes several tasks:
Task a: Print given sentence with float number, that has 2 digits before and after the decimal point.
Tasl b: Print character 'H' in different ways.
Task c: Count characters inside given sentence.
Task d: Display the same float number in different ways.
--------------
*/
#include <stdio.h>
#include <string.h> // Library for task 'с'. Includes function "strlen()"
#define Q "His Hamlet was funny without being vulgar." // Sentence for task 'с'
int main(void) {
	printf("He sold the painting for $%2.2f. \n", 2.345e2); // Task 'a'
	printf("%c%c%c\n",'H', 105, '\41'); // Task 'b'
	printf("' %s '\nhas %ld characters.\n", Q, strlen(Q)); // Task 'c'
	printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0); // Task 'd'
	return 0;
}
