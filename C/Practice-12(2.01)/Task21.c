/*
----------------
Name: Task21.c
------------------------------------------------------------
Description: Create a function to refer to hash-table 
  elements sequence in unsorted order.
------------------------------------------------------------
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

void puthash(int *num) {
	Nameval *sym;
	int counter = 0;
	for (int i = 0; i < NHASH; i++) {
		for (sym = symtab[i]; sym != NULL; sym = sym->next) {
			printf("(%d)%s .%d\n", counter + 1, sym->name, sym->value);
			counter++;
		}
	}
	(*num) = counter;
}

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
  
	int counter;
	puthash(&counter);
	printf("Num of hash table elements - %d\n", counter);
	return 0;
}
