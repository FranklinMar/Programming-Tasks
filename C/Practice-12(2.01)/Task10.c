/*
----------------
Name: Task10.c
------------------------------------------------------------
Description: Write a program, that will have recursive and 
  iterative implementations of reverse_list function, that 
  would reverse the order of elements of the list. Do not 
  create new elements of the list. Use only existing 
  elements, like in the example above.
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
Nameval *reverse_list(Nameval *listp) {
	Nameval *temp;
	if (listp == NULL || listp->next == NULL) {
		return listp;
	}
	temp = reverse_list(listp->next);
	listp->next->next = listp;
	listp->next = NULL;
	return temp;
}
Nameval *reverse_iter(Nameval *listp) {
    Nameval *temp = NULL;
    while (listp) {
        Nameval *next = listp->next;
		listp->next = temp;
        temp = listp;
        listp = next;
    }
    return temp;
}
Nameval *newitem(char *name, int value) {
	Nameval *newp;
	newp = (Nameval *) malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}
Nameval *addfront(Nameval *listp, Nameval *newp) {
	newp->next = listp;
	return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp) {
	if (listp == NULL) 
    return newp;
	Nameval *p;
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}

int main(void) {
	Nameval *nvlist = NULL;
	nvlist = addfront(nvlist, newitem(“data1”, 10));
	printf("%s %d\n", nvlist->name, nvlist->value);
  
	Nameval *item = newitem(“data2”, 45);
	nvlist = addend(nvlist, item);
	printf("%s %d\n", item->name, item->value);
  
	nvlist = reverse_iter(nvlist);
	printf("%s %d\n", nvlist->name, nvlist->value);
	printf("%s %d\n", nvlist->next->name, nvlist->next->value);
  
	nvlist = reverse_list(nvlist);
	printf("%s %d\n", nvlist->name, nvlist->value);
	printf("%s %d\n", nvlist->next->name, nvlist->next->value);
	return 0;
}
