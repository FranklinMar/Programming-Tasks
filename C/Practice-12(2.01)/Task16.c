/*
----------------
Name: Task16.c
------------------------------------------------------------
Description: Write a sorting function with symmetrical 
  traversion just like in "Tree-traverser" example. What 
  will be the speed formula of this function? Under which 
  circumstanses will it have bad performance? What are its 
  stats in comparison to Quick sort algorithm and functions 
  from the library?
------------------------------------------------------------
*/

/*
Answer:

This function could have bad performance, when the parameters 
(input), are sorted in any way. Because of that, the 
resulting  binary tree would be unbalanced and it will 
unnecessarily load the CPU of computer, because of recursion.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *left;
	Nameval *right;
};

Nameval *insert(Nameval *treep, Nameval *newp) {
	if (treep == NULL)
		return newp;
	int cmp = strcmp(newp->name, treep->name);
	if (cmp == 0)
		printf("insert: duplicate entry %s ignored",newp->name);
	else if (cmp < 0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;
}

void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg) {
	if (treep == NULL)
		return;
	applyinorder(treep->left, fn, arg);
	(*fn)(treep, arg);
	applyinorder(treep->right, fn, arg);
}

void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg) {
	if (treep == NULL)
		return;
	applypostorder(treep->left, fn, arg);
	applypostorder(treep->right, fn, arg);
	(*fn)(treep,arg);
}

void printnv(Nameval *p, void *arg) {
	char *fmt;
	fmt = (char *) arg;
	printf(fmt, p->name, p->value);
}

int main(void) {
	Nameval *treep = NULL;
	treep = insert(treep, &(struct Nameval) {.name="Andy", .value=12});
	treep = insert(treep, &(struct Nameval) {.name="Billy",.value=18});
	applyinorder(treep, printnv, "%s: %d\n");
	putchar('\n');
	applypostorder(treep,printnv, "%s: %d\n");
	return 0;
}
