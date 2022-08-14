/*
------------------
Name: Task10.cpp
------------------------------------------------------------
Description: Create a singly-linked list (see Unit 1 "A 
  singly-linked list") using "new", and implement possible 
  operations on this list, namely: adding element, delete 
  element, copy element, merge, split, paste before or after 
  a specific element.
------------------------------------------------------------
*/
#include <iostream>
using namespace std;

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *newitem(char *name, int value) {
	Nameval *newp;
	newp = new Nameval;
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
			delete p->name;
			delete p;
			return listp;
		}
		prev = p;
	}
	printf("delitem: %s not in list", name);
	return NULL;
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

void printncount(Nameval *list, int *num) {
	cout << list->name << ".Age:" << list->value << endl;
	(*num)++;
	if (list->next != NULL)
		printncount(list->next, num);
}

void pasteafter(Nameval *list, Nameval *copy, int index) {
	int i = 0;
	Nameval *p;
	if (index == 0) {
		copy->next = list->next;
		list->next=copy;
	} else {
		for (p = list; p->next != NULL && i < index; i++)
			p = p->next;
		copy->next = p->next;
		p->next = copy;
	}
}
void pastebefore(Nameval *list, Nameval *copy, int index) {
	if (index == 0) {
		Nameval t;
		t = *list;
		*list = *copy;
		*copy = t;
		list->next = copy;
	} else {
		int i = 0;
		Nameval *p;
		Nameval *k;
		for (p = list; p->next != NULL && i < index - 1; i++) {
			p = p->next;
		}
		k = p;
		k = k->next;
		p->next = copy;
		copy->next = k;
	}
}

void copy(Nameval *list, int num) {
	int ind, elem;
	int count = 0;
	bool i = false;
	Nameval *cpy;
	cpy = new Nameval;
	cout << "Choose an element to copy:\n";
	Nameval *p;
	for (p = list; p != NULL; p = p->next) {
		count++;
		cout << count << ". " << p->name << " ," << p->value << endl;
	}
	cout << "Enter available elements (use 1,2..)\n";
	do {
		cin >> ind;
		if (ind <= 0 || ind > count || !cin.good()) {
			cin.clear();
			cout << "\nwrong element,please try again\n";
			cin.ignore();
			i = true;
		} else {
			i = false;
		}
	} while(i);
	ind--;
	p = list;
	for (int i = 0; i < ind; p = p->next, i++);
	*cpy = *p;
	cout << "Copied element:" << cpy->name << " ," << cpy->value << endl;
	cout << "Choose how to paste:\n";
	cout << "1.Paste before chosen element. 2.Paste after chosen element.\n";
	
	do {
		cin >> ind;
		if (ind <= 0 || ind > 2 || !cin.good()) {
			cin.clear();
			cout << "\nwrong action,please try again\n";
			cin.ignore();
			i = true;
		} else {
			i = false;
		}
	} while(i);
	cout << "Choose an element where to copy:\n";
	count = 0;
	for (p = list; p != NULL; p = p->next) {
		count++;
		cout << count << ". " << p->name << " ," << p->value << endl;
	}
	do {
		cin >> elem;
		if (elem <= 0 || elem > count || !cin.good()) {
			cin.clear();
			cout << "\nwrong element,please try again\n";
			cin.ignore();
			i = true;
		} else {
			i = false;
		}
	} while(i);
	elem--;
	if (ind == 1) {
		pastebefore(list, cpy, elem);
	} else {
		pasteafter(list, cpy, elem);
	}
}

int main() {
	int number = 0;
	Nameval list = {.name="Andriy", .value=17};
	addend(&list, newitem("Arkasha", 6));
	addend(&list, newitem("Daryna", 3));
	printncount(&list, &number);
	cout << "Total(Elements):" << number << endl;//"Total(Elements):%d\n",number);
	copy(&list, number);
	cout << "List:\n";
	for (Nameval *p = &list; p != NULL; p = p->next, number++) {
		cout << p->name << " ,"<< p->value << endl;
	}
	Nameval *list1;
	Nameval *list2;
	cout << "\nSplitting list:\n";
	cout << "\nlist1\n";
	split(&list, &list1, &list2);
	printncount(list1, &number);
	cout << "\nlist2\n";
	printncount(list2, &number);
	cout << "\nUniting lists:\n";
	list1 = unite(list1, list2);
	printncount(list1, &number);
	return 0;
}
