/*
----------------
Name: Task14A.c
------------------------------------------------------------
Description: A tree, in which any path from root to leaf has 
  approximately the same length, is called balanced. It's 
  advantage is that the search of element has running time 
  of O(log n), because, just like in binary search, by each 
  step the half of data that remained is ignored.
  
  Write a program by looking at the example shown in the 
  first lecture "Binary search tree". Implement the 
  posibility of generating the stream of data for filling up 
  the tree. As data is received, a node should be formed for 
  each element.
  
- SubTask 2:
  The data is received in sorted order. Create a function of 
  checking the balance state of the created tree, to confirm 
  or deny the next statement:
  If the elements are passed in sorted order, then the 
  traversing the tree down will always be performed till the 
  very bottom of certain branch of the tree, actually 
  respresenting itself as a linked list by "right" pointer.
  This problem is caused by speed problem, that lists have.
------------------------------------------------------------
*/
/*
Answer to the statement:
By passing elements to the tree is sorted order, traversing 
the tree (down) will really be performed to the very bottom 
by one of the branches of the tree. The tree itself will 
perform itself as a list by one of either directions (left 
or right), depending on how the passed data was sorted.
Ascending order = right, descending order = left.
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
	if(treep == NULL) {
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
	struct Nameval newv = {.name="Andy", .value=12};
	printf("%s %d\n", newv.name, newv.value);
	treep = insert(treep, &newv);
	
	treep = insert(treep, &(struct Nameval) {.name="Billy", .value=18});
	Nameval *res = lookup(treep, "Billy");
	treep = insert(treep, &(struct Nameval) {.name="Carl", .value = 21});
	treep = insert(treep, &(struct Nameval){.name="Daniel", .value = 17});
	treep = insert(treep, &(struct Nameval){.name="Emily", .value = 15});
	
	printf("%s %d\n", res->name, res->value);
	res = nrlookup(treep, "Andy");
	printf("%s %d\n", res->name, res->value);
	int balance = isBalanced(treep);
	if (balance) {
		printf("Binary tree is balanced\n");
	} else {
		printf("Binary tree is unbalanced\n");
	}
	return 0;
}
