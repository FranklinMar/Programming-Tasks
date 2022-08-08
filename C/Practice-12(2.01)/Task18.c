/*
----------------
Name: Task18.c
------------------------------------------------------------
Description: Copy the code of program "Hash Table", and 
  check it's efficiency and answer the question:
  What should be the size of the array in this example?
  The general idea of this example is that array "symtab" 
  must be quite big to make the lists of each hash-code 
  to have as least elements as possible, and the search 
  operation would have O(1) speed.
------------------------------------------------------------
*/
/*
Answer:

The size of array "symtab" must be a prime number and be 
quite big for efficient hash-coding and searching, so lists 
must be as small as possible.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 11

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *symtab[NHASH];

enum { MULTIPLIER = 31 };

unsigned int hash(char *str) {
	unsigned int h = 0;
	unsigned char *p;
	for (p = (unsigned char *) str; *p != '\0'; p++)
		h = MULTIPLIER * h + *p;
	return h % NHASH;
}

Nameval* lookup(char *name, int create, int value) {
	Nameval *sym;
	int h = hash(name);
	for (sym = symtab[h]; sym != NULL; sym = sym->next)
		if (strcmp(name, sym->name) == 0)
			return sym;
	if (create) {
		sym = (Nameval *) malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

int main(void) {
	Nameval *node = lookup("Billy", 1, 12);
	printf("%s %d\n", node->name, node->value);
	node = lookup("Andy", 1, 18);
	printf("%s %d\n", node->name, node->value);
	return 0;
}
