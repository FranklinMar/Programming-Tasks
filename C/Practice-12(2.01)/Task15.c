/*
----------------
Name: Task15.c
------------------------------------------------------------
Description: Compare the speed of function lookup() and 
  nvlookup from example "Binary search tree" from the first 
  lecture. Give answer on the question: What is the 
  difference between recursive and iterative alternatives?
------------------------------------------------------------
*/

/*
Because of the speed of computation of the computer, comparing both 
functions is possible only when the amount of data is very very large.
The difference between recursive and iterative forms of function is 
that iterative function uses loops instead of recursion, thus it takes 
less memory and CPU to compute. Recursive function is looping by 
calling itself, using more memory and CPU but because of this they are 
more flexible and useful for complex algorithms.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *left;
	Nameval *right;
};
Nameval *lookup(Nameval *treep, char *name){
	if (treep == NULL)
		return NULL;
	int cmp = strcmp(name, treep->name);
	if (cmp == 0)
		return treep;
	else if (cmp < 0)
		return lookup(treep->left, name);
	else
		return lookup(treep->right, name);
}
Nameval *nrlookup(Nameval *treep, char *name){
	while (treep != NULL) {
		int cmp = strcmp(name, treep->name);
		if (cmp == 0)
			return treep;
		else if (cmp < 0)
			treep = treep->left;
		else
			treep = treep->right;
	}
	return NULL;
}
Nameval *insert(Nameval *treep, Nameval *newp){
	if (treep == NULL)
		return newp;
	int cmp = strcmp(newp->name, treep->name);
	if(cmp == 0)
		printf("insert: duplicate entry %s ignored", newp->name);
	else if (cmp < 0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;
}

int main(void){
	Nameval *treep = NULL;
	struct Nameval newv = {.name="Andy", .value=12};
	printf("%s %d\n", newv.name, newv.value);
	treep = insert(treep, &newv);
	treep = insert(treep, &(struct Nameval) {.name="Billy", .value=18});
	clock_t start = clock();
	Nameval *res = lookup(treep, "Andy");
	printf("iterative function 'lookup':%lf s\n", (double)(clock() - start) / CLK_TCK);
	printf("%s %d\n", res->name, res->value);
	clock_t start1 = clock();
	res = nrlookup(treep,"Andy");
	printf("recursive function 'lookup':%lf s\n", (double)(clock() - start1) / CLK_TCK);
	printf("%s %d\n", res->name, res->value);
	return 0;
}
