/*
----------------
Name: Task20.c
------------------------------------------------------------
Description: Hash-function from "Hash Table" lecture 
  example has a general stats and is pretty good to work 
  with rows. However, it can be ineffective with some input.
  Create a input data, that would make this function to work
  ineffectively.
------------------------------------------------------------
*/
/*
Answer:

Input data that would make this function inefficient may 
have only a few characters sequence. But, with bigger number 
of characters, task to build such input data becomes more 
complex and harder. This character sequence depends on the 
value of "NHASH" variable.
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

Nameval* lookup(char *name, int create, int value){
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
	node = lookup((char *)'!', 1, 18);
	printf("%s %d\n", node->name, node->value);
	return 0;
}
