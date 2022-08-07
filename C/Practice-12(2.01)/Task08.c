/*
----------------
Name: Task08.c
------------------------------------------------------------
Description: Go back again to the code of the program, 
  displayed in the first lecture and written by yourself in 
  the previous task. Modify it as follows:

  Create a function coolfun(), that will go through all 
  elements of the list and will call function, passed as 
  an argument, for every element separately.
  
  coolfun() function must be flexible, so the other function 
  could be passed to it as an argument. By doing that, it 
  could use this function, created for the elements, 
  independently for each element.
  
  That way, coolfun() function must have 3 parameters: 
  - the list itself;
  - pointer to the function, that is called for each element 
    of the list;
  - argument for passing into the previously defined function.
  
  Prototype: void coolfun (Nameval *listp, void (* fn) (Nameval *, void *), void* arg);
  
  Example:
  - "fn" function:
  // Inccounter: increments "*arg* counter
  void inccounter (Nameval *p, void *arg) {
    int *ip;
    ip = (int *) arg;
    (*ip)++;
  }
  
  The coolfun() function is called by next expression:
    int n = 0;
    coolfun(nvlist, inccounter, &n);
    printf("%d elements in nvlist\n", n);
------------------------------------------------------------
*/
#include <stdio.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

void inccounter(Nameval *p, void *arg) { 
	int *ip; 
	ip = (int *)arg; 
	(*ip)++; 

	printf("%s.Age:%d\n", p->name, p->value);
}
void coolfun(Nameval *listp, void (*fn)(Nameval*, void*), void *arg) {
	if (listp == NULL);
	else {
		(*fn)(listp, arg);
		coolfun(listp->next, fn, arg);
		/*
		Nameval *p;
		for(p=listp;p->next !=NULL;p = p->next){
			(*fn)(listp,arg);
		}
		*/
	}
}
void addnew(Nameval *list, Nameval *newobj){
	if (list->next == NULL){
		list->next = newobj;
	} else {
		addnew(list->next, newobj);
	}
}
int main() {
	int number = 0;
	Nameval list = {.name = "Andriy", .value=17};
	addnew(&list, &(struct Nameval) {.name = "Arkasha", .value = 6});
	addnew(&list, &(struct Nameval) {.name = "Daryna", .value = 6});
	coolfun(&list, inccounter, &number);
	printf("%s %d\n", list.next->name, list.next->value);
	printf("Total(Elements):%d\n", number);
	return 0;
}
