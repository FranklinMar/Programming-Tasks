/*
------------------
Name: Task06.cpp
------------------------------------------------------------
Description: Implement the solution of Problem 2.5 (see 
  Unit 1 "A singly-linked list") on C language. Example of 
  looped queue, built with the help of pointers.
  
    o     |-----------------------------------------------|
    |  ___v_______   ___________   ___________   _________|_
    |->|Data 1| o|-->|Data 2| o|-->|Data 3| o|-->|Data 3| o|
       -----------   -----------   -----------   ---^-------
                                               0----|
                                               
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
}*head, *tail;


Nameval *newitem (char *name, int value) {
	Nameval *newp;
	newp = (Nameval *) malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *q_initialize(Nameval *listp, int *num) {
	Nameval *temp = listp;
	*num = 1;
	for (; temp->next != NULL; temp = temp->next, (*num) = *num + 1);
	temp->next = listp;
	head = listp;
	tail = temp;
	return listp;
}

Nameval *addfront(Nameval *listp, Nameval *newp) {
	newp->next = listp;
	return newp;
}

Nameval *q_show(Nameval *listp, int *num) {
	if (*num == 0) {
		printf("The Queue is empty\n");
		return head;
	}
	if (head == listp) {
		printf("Beginning of Queue\n");
	} else if (listp == tail && *num != 0) {
		printf("Name:%s.Value:%d.\n", listp->name, listp->value);
		printf("End of Queue\n");
		(*num)--;
		return listp->next;
	}
	(*num)--;
	printf("Name:%s.Value:%d.\n", listp->name, listp->value);
	listp = listp->next;
	return listp;
}

Nameval *addend(Nameval *listp, Nameval *newp){
	if (listp == NULL) 
    return newp;
	Nameval *p;
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}

int main(void) {
	Nameval *nvlist = NULL;
	nvlist = addfront(nvlist, newitem("data1", 6));
	int num;
	Nameval *item = newitem("data2", 13);
	nvlist = addend(nvlist, item);
	nvlist = addend(nvlist, newitem("data3", 23));
	nvlist = addend(nvlist, newitem("data4", 45));
	nvlist = q_initialize(nvlist, &num);
	nvlist = q_show(nvlist, &num);
	nvlist = q_show(nvlist, &num);
	nvlist = q_show(nvlist, &num);
	nvlist = q_show(nvlist, &num);
	nvlist = q_show(nvlist, &num);
	return 0;
}
