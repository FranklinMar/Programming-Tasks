/*
----------------
Name: Task09.c
------------------------------------------------------------
Description: Add and modify the previous program code to 
  add some other possible operations with the list, in example:
	
	- copying;
	- merging;
	- splitting;
	- inserting before certain element;
	- inserting after certain element.
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

void addnew(Nameval *list, Nameval *newobj) {
	if (list->next == NULL) {
		list->next = newobj;
	} else {
		addnew(list->next, newobj);
	}
}

void split(Nameval *list, Nameval **list1, Nameval **list2) {
  Nameval **even = list1;
  Nameval **odd = list2;

  for (; list != NULL; list = list->next)
    if (list->value % 2 == 0) {
      *even = list;
      even = &(*even)->next;
    } else {
      *odd = list;
      odd = &(*odd)->next;
    }
  *even = NULL;
  *odd = NULL;
}

Nameval* unite(Nameval* list1, Nameval* list2) {
  Nameval* result = NULL;
  result = list1;
	for (; list1->next != NULL; list1 = list1->next);
	list1->next = list2;
	return result;
}

void pastebefore(Nameval *list, Nameval *copy, int index, int num) {
	int i = 0;
	Nameval *p;
	Nameval *k;
	if (index == 0) {
		p = list;
		copy->next = p;
		list = copy;
	} else if (index == num-1) {
		for (p = list; p->next != NULL && i < num; i++) {
			p = p->next;
		}
		k = p;
		p = p->next;
		k->next = copy;
		copy->next = p;
	} else {
	  for (p = list; p->next != NULL && i < index; i++) {
	  	 p = p->next;
	  }
	  copy->next = p;
	  for (p = list; p->next != NULL && i < index - 1; i++) {
	  	 p = p->next;
	  }
	  p->next = copy;
	}
  // Print out (for testing)
	i = 0;
	for (p = list; p != NULL; p = p->next) {
		i++;
		printf("%d. %s ,%d\n",i,p->name,p->value);
	}
}

void pasteafter(Nameval *list, Nameval *copy, int index, int num) {
	int i = 0;
	Nameval *p;
	if (index == 0) {
		copy->next = list->next;
		list->next = copy;
	} else if (index == num - 1) {
		for (p = list; p->next != NULL; p = p->next);
		p->next = copy;
		copy->next = NULL;
	} else {
  	for (p = list; p->next != NULL && i < index; i++) {
			p = p->next;
		}
		copy->next = p->next;
		p->next = copy;
	}
	// Print out (for testing)
	i = 0;
	for (p = list; p != NULL; p = p->next) {
		i++;
		printf("%d. %s ,%d\n", i, p->name, p->value);
	}
}
void printncount(Nameval *list, int *num) {
	printf("%s.Age:%d\n", list->name, list->value);
	(*num)++;
	if (list->next != NULL) {
		printncount(list->next, num);
	}
}
void copy(Nameval *list, int num) {
	int ind, elem;
	int count = 0;
Nameval cpy;
	printf("Choose an element to copy:\n");
	Nameval *p;
	for (p = list; p->next != NULL; p = p->next) {
		count++;
		printf("%d. %s ,%d\n", count, p->name, p->value);
	}
	if (p->next == NULL && p->name != NULL) {
		count++;
		printf("%d. %s ,%d\n", count, p->name, p->value);
	}
	printf("Enter only available elements (use 1,2..)\n");
	scanf("%d", &ind);
	ind--;
	p = list;
	for (int i = 0; i < ind; p = p->next, i++);
	cpy = *(p);
	printf("Copied element:%s ,%d\n", cpy.name, cpy.value);
	printf("Choose how to paste:\n");
	printf("1.Paste before chosen element. 2.Paste after chosen element.\n");
	scanf("%d", &ind);
	printf("Choose an element on which to copy:\n");
	count = 0;
	for (p = list; p->next != NULL; p = p->next) {
		count++;
		printf("%d. %s ,%d\n", count, p->name, p->value);
	}
	if (p->next == NULL && p->name != NULL) {
		count++;
		printf("%d. %s ,%d\n", count, p->name, p->value);
	}
	scanf("%d", &elem);
	elem--;
	if (ind == 1) {
		pastebefore(list, &cpy, elem, num);
	} else {
		pasteafter(list, &cpy, elem, num);
	}
}

int main() {
	int number=0;
	Nameval list = {.name = "Andriy", .value=17};
	addnew(&list, &(struct Nameval) {.name = "Arkasha", .value = 6});
	addnew(&list, &(struct Nameval) {.name = "Daryna", .value = 3});
	printncount(&list, &number);
	printf("%s %d\n", list.next->name, list.next->value);
	printf("Total(Elements):%d\n", number);
	copy(&list, number);
	Nameval *list1;
	Nameval *list2;
	split(&list, &list1, &list2);
	printncount(list1, &number);
	printf("END\n");
	printncount(list2, &number);
	printf("END\n");
	list1 = unite(list1, list2);
	printncount(list1, &number);
	return 0;
}
