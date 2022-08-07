/*
----------------
Name: Task07.c
------------------------------------------------------------
Description: In the example program of the first lecture 
  "A singly-linked list" write a function for displaying all 
  elements of the list. The function must go through every 
  element of the list and gradually print out every element 
  to the console on the display.
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

void addnew(Nameval *list, Nameval *newobj) {
	if (list->next == NULL) {
		list->next = newobj;
	} else {
		addnew(list->next, newobj);
	}
}

void printstack(Nameval *list, int *num) {
	printf("%s.Age:%d\n", list->name, list->value);
	(*num)++;
	if (list->next != NULL) {
		printstack(list->next, num);
	}
	/*
	Non recursive alternative:
	Nameval *p = list;
	int i = 0
	for(;p->next != NULL; p = p->next,i++){
		printf("(%d)%s.Age:%d\n",i,p->name,p->value);
	}
	*num = i;
	*/
}

int main() {
	int number = 0;
	Nameval list = {.name = "Andriy", .value=17};
	addnew(&list, &(struct Nameval) {.name = "Arkasha", .value = 6});
	addnew(&list, &(struct Nameval) {.name = "Daryna", .value = 6});
	printstack(&list, &number);
	printf("%s %d\n", list.next->name, list.next->value);
	printf("Total(Elements):%d\n", number);
	return 0;
}
