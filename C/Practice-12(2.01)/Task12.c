/*
----------------
Name: Task12.c
------------------------------------------------------------
Description: Write a program and implement untyped pointer 
  definitions of Type_List in C language. The simplest way -
  include "void *" pointer for every element of the list.
  
  Now, try to do the same in C++ in the way of template, 
  by defining class Type_List with elements of "Object" type
------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Typelist Typelist;

struct Typelist{
  void *element;
  Typelist *next;
};

Typelist *newitem(void *new) {
	Typelist *newp;
	newp = (Typelist *) malloc(sizeof(Typelist));
	newp->element = new;
	newp->next = NULL;
	return newp;
}
int main(void) {
	Typelist *list = NULL;
	list = newitem((char *) "Hello");
	list->next = newitem((int *) 6);
	printf("%s %d", list->element, list->next->element);
	return 0;
}
