/*
----------------
Name: Task11.c
------------------------------------------------------------
Description: In the previous example, function delitem(), 
  just like freeall() function, doesn't free the memory of 
  "name" field. Rewrite the program to modify both of these 
  functions, so they would as well free the memory allocated 
  to the "name" field.
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

Nameval *newitem(char *name, int value) {
	Nameval *newp;
	newp = (Nameval *) malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *delitem(Nameval *listp, char *name) {
	Nameval *p, *prev;
	prev = NULL;
	for (p = listp; p != NULL; p = p->next) {
		if (strcmp(name, p->name) == 0) {
			if (prev == NULL)
				listp = p->next;
			else
				prev->next = p->next;
			free(p->name);
			free(p);
			return listp;
		}
		prev = p;
	}
	printf("delitem: %s not in list", name);
	return NULL;
}
void freeall(Nameval *listp){
	Nameval *next;
	for (; listp != NULL; listp = next) {
		next = listp->next;
		free(listp->name);
		free(listp);
	}
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

int main(void){
	Nameval *nvlist = NULL;
	char *text1;
	char *text2;
	/* 
"free()" function can only free the dynamically allocated memory,
meaning memory, allocated with malloc(); realloc() and calloc() functions etc.
So, we must allocate input data dynamically to make function could work without errors.
  */
	text1 = (char *) malloc(sizeof(char) * 10);
	text2 = (char *) malloc(sizeof(char) * 10);
	if (text1 == NULL) 
    return 0;
	if (text2 == NULL) 
    return 0;
	*text1 = ' ';
	*text2 = ' ';
	char tex1[] = "data1";
	char tex2[] = "data2";
	strcpy(text1, tex1);
	strcpy(text2, tex2);
	nvlist = addfront(nvlist, newitem(text1, 10));
	printf("%s %d\n", nvlist->name, nvlist->value);
	
	Nameval *item = newitem(text2, 45);
	nvlist = addend(nvlist, item);
	printf("%s %d\n", item->name, item->value);
	//freeall(nvlist);
	nvlist = delitem(nvlist,text1);
	printf("%s %d\n", nvlist->name, nvlist->value);
	printf("%s %d\n", item->name, item->value);
	return 0;
}
