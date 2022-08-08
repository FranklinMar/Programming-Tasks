/*
----------------
Name: Task14A.c
------------------------------------------------------------
Description: .
------------------------------------------------------------
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
int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
int height(Nameval * treep) {
  if (treep == NULL) {
		return 0; 
	}
	int current = 1 + max(height(treep->left), height(treep->right));
  return current;
}

int isBalanced(Nameval * treep) {
	if (treep == NULL) {
		return 1;
	}
	int l = isBalanced(treep->left);
	int r = isBalanced(treep->right);
	int balance = (l && r);
	int diff = abs(height(treep->left) - height(treep->right));
	return (balance && (diff <= 1));
}
Nameval *lookup(Nameval *treep, char *name) {
	if (treep == NULL)
		return NULL;
	int cmp = strcmp(name, treep->name);
	if(cmp == 0)
		return treep;
	else if (cmp < 0)
		return lookup(treep->left, name);
	else
		return lookup(treep->right, name);
}
Nameval *nrlookup(Nameval *treep, char *name) {
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
Nameval *insert(Nameval *treep,Nameval *newp) {
	if(treep == NULL)
		return newp;
	int cmp = strcmp(newp->name, treep->name);
	if (cmp == 0)
		printf("insert: duplicate entry %s ignored", newp->name);
	else if (cmp<0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;
}
int main(void) {
	Nameval *treep = NULL;
	struct Nameval newv = {.name="1"/*Andy*/, .value=12};
	printf("%s %d\n", newv.name, newv.value);
	treep = insert(treep, &(struct Nameval) {.name="3", .value = 21});
	treep = insert(treep, &(struct Nameval) {.name="5", .value = 15});
	treep = insert(treep, &(struct Nameval) {.name="2", .value=18});
	treep = insert(treep, &newv);
	treep = insert(treep, &(struct Nameval) {.name="4", .value = 17});

	int balance = isBalanced(treep);
	if (balance) {
		printf("Binary tree is balanced\n");
	} else {
		printf("Binary tree is unbalanced\n");
	}
	return 0;
}
/*
Answer to the statement:
Надходження елементiв у дерево у хаотичному порядку
дiйсно робить дерево бiльш збалансованим,але в рiдких випадках,
коли серединнi елементи займають мiсце кореня дерева.
*/
